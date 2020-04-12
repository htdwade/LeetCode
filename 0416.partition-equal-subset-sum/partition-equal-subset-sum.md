# 416. 分割等和子集

## 题目描述

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

1. 每个数组中的元素不会超过 100
2. 数组的大小不会超过 200

示例 1:
```java
输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
```

示例 2:
```java
输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
```

## 解题思路

题目可以看做选取数组中的一些数使其和为sum/2的01背包问题。套用01背包模板即可,dp[i, j]表示前i个数是否能构成和为j的背包，则有：
```java
dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]] // 第i个数选或者不选
```
优化成一维空间则有：dp[i] = dp[i] | dp[i - num]，背包大小从后往前遍历。

## 解题代码

### Java

```java
class Solution {
    public boolean canPartition(int[] nums) {
        if(nums == null || nums.length == 0)
            return false;
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 == 1)
            return false;
        boolean[] dp = new boolean[sum / 2 + 1];
        dp[0] = true;
        for(int num : nums) {
            for(int i = sum / 2; i >= num; i--) {
                dp[i] = dp[i] | dp[i - num];
            }
        }
        return dp[sum / 2];
    }
}
```