# 322. 零钱兑换

## 题目描述

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
```java
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
```
示例 2:
```java
输入: coins = [2], amount = 3
输出: -1
```
说明:
你可以认为每种硬币的数量是无限的。

## 解题思路

完全背包问题。套用模板，dp[i]表示总金额为i的情况下所需的最少硬币个数，则有dp[i] = min(dp[i], dp[i - coin] + 1)，因为需要恰好装满背包，所以初始化的时候只有dp[0] = 0，其余均为无效值。

## 解题代码

### Java

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for(int coin : coins)
            for(int i = coin; i <= amount; i++)
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
}
```