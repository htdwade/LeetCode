# 518. 零钱兑换 II

## 题目描述

给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:
```java
输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```
示例 2:
```java
输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
```
示例 3:
```java
输入: amount = 10, coins = [10] 
输出: 1
```

注意:

你可以假设：

* 0 <= amount (总金额) <= 5000
* 1 <= coin (硬币面额) <= 5000
* 硬币种类不超过 500 种
* 结果符合 32 位符号整数

## 解题思路

完全背包问题。套用模板，dp[i]表示总金额为i的情况下的硬币组合数，则有dp[i] = sum(dp[i], dp[i - coin])，因为需要恰好装满背包，所以初始化的时候只有dp[0] = 1，其余均为无效值0。

## 解题代码

### Java

```java
class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for(int coin : coins)
            for(int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        return dp[amount];
    }
}
```