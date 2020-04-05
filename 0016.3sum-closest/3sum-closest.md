# 16. 最接近的三数之和

## 题目描述

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
```java
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
```

## 解题思路

采用3sum的思路，先数组排序，遍历数组，固定nums[i], 令left=i+1，right=n-1。
* 若nums[i]+nums[left]+nums[right] == target，则直接返回和。
* 若和大于target，right--；
* 若和小于target，left++；
* 更新结果为距离target更近的和。


## 解题代码

### Java

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums == null || nums.length < 3)
            return 0;
        Arrays.sort(nums);
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.length;
        for(int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target)
                    return sum;
                else if(sum < target)
                    left++;
                else
                    right--;
                if(Math.abs(sum - target) < Math.abs(res - target))
                    res = sum;
            }
        }
        return res;
    }
}
```