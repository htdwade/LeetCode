# 4. 寻找两个有序数组的中位数

## 题目描述

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
```java
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
```
示例 2:
```java
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
```

## 解题思想

此题更通用的形式是求两个有序数组中第k小的数。
对于两个有序数组 a[1…m], b[1…n]，求两个数组合一起后第 k 小的数，假设 m < n，在数组 a 中找到第 k / 2 小的数 ai，在数组 b 中找到第 k - i 小的数 bj（不说 k / 2 是为了避免 k 的奇偶造成的 i + j 不一定等于 k 的情况），i + j = k。（注意 k / 2 可能大于 m，若大于 m，则用 am 代替 ai，此时 j = k - m)

i 和 j 将数组a，b分别划分为两部分，比较 ai 和 bj 的大小：

* 若ai > bj，说明第 k 小的数不可能出现在数组 a 的右部，也不可能出现在数组 b 的左部（用反证法可证），舍弃这部分，在 a 的左部(包含 ai)和 b 的右部(不包含 bj)中查找第 k - j 小的数。(因为此时 b[1…j] 必然在前 k 个数中)
* 若ai < bj，说明第 k 小的数不可能出现在数组 a 的左部，也不可能出现在数组 b 的右部（用反证法可证），舍弃这部分，在 a 的右部(不包含 ai)和 b 的左部(包含 bj)中查找第 k - i 小的数。(因为此时 a[1…i] 必然在前 k 个数中)
* 若ai = bj，说明第 k 小的数就是 ai，可并入上述两种情况之一。

时间复杂度分析：k = (m + n) / 2，且每次递归 k 的规模都减少一半，因此时间复杂度是 O(log(m + n)) .

## 解题代码

### C++

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        if(len & 0x1 == 1)
            return findKthNum(nums1, 0, m, nums2, 0, n, len / 2 + 1);
        else
            return (findKthNum(nums1, 0, m, nums2, 0, n, len / 2) + findKthNum(nums1, 0, m, nums2, 0, n, len / 2 + 1)) / 2.0;
    }

private:
    int findKthNum(vector<int>& nums1, int start1, int m, vector<int>& nums2, int start2, int n, int k){
        if(m > n)
            return findKthNum(nums2, start2, n, nums1, start1, m, k);
        if(m == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);
        int i = min(m, k / 2);
        int j = k - i;
        if(nums1[start1 + i - 1] > nums2[start2 + j - 1])
            return findKthNum(nums1, start1, i, nums2, start2 + j, n - j, k - j);
        else
            return findKthNum(nums1, start1 + i, m - i, nums2, start2, j, k - i);
    }
};
```

### Java

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int len = m + n;
        if((len & 0x1) == 1)
            return findKthNum(nums1, 0, m, nums2, 0, n, len / 2 + 1);
        else
            return (findKthNum(nums1, 0, m, nums2, 0, n, len / 2) + findKthNum(nums1, 0, m, nums2, 0, n, len / 2 + 1)) / 2.0;
    }

    public int findKthNum(int[] nums1, int start1, int m, int[] nums2, int start2, int n, int k) {
        if(m > n)
            return findKthNum(nums2, start2, n, nums1, start1, m, k);
        if(m == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return Math.min(nums1[start1], nums2[start2]);
        int i = Math.min(k / 2, m);
        int j = k - i;
        if(nums1[start1 + i - 1] > nums2[start2 + j - 1])
            return findKthNum(nums1, start1, i, nums2, start2 + j, n - j, k - j);
        else
            return findKthNum(nums1, start1 + i, m - i, nums2, start2, j, k - i);
    }
}
```
