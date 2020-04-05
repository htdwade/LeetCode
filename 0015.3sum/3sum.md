# 15. 三数之和

## 题目描述

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：
```java
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## 解题思路

* 如果数组为 null 或者数组长度小于 3，返回 []。
* 对数组进行排序。
* 遍历排序后数组，若 nums[i] > 0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
* 对于重复元素：跳过，避免出现重复解
* 令左指针 L=i+1，右指针 R=n-1，当 L < R 时，执行循环：
    * 若 nums[i]+nums[L]+nums[R]==0，加入结果集，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解；
    * 若和大于 0，说明 nums[R] 太大，R 左移；
    * 若和小于 0，说明 nums[L] 太小，L 右移。

## 解题代码

### Java

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums == null || nums.length < 3)
            return res;
        Arrays.sort(nums);
        int n = nums.length;
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] > 0)
                return res;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    while(left < right && nums[left] == nums[left + 1])
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
}
```
