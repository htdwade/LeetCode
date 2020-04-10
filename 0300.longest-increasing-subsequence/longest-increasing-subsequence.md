# 300. 最长上升子序列

## 题目描述

给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
```java
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```
说明:

* 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
* 你算法的时间复杂度应该为 O(n2) 。

## 解题思路

设dp[i]表示[0...i]区间中以nums[i]结尾的最长上升子序列的长度，则状态转移方程为：
```java
dp[i]=max(dp[j])+1, 其中0≤j<i且num[j]<num[i]
```
整个数组的最长上升子序列即所有 dp[i] 中的最大值。

## 解题代码

### Java

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0)
            return 0;
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        int res = 0;
        for(int i = 0; i < nums.length; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
```