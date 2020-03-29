# 714. 买卖股票的最佳时机含手续费

## 题目描述

给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

示例 1:
```java
输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
输出: 8
解释: 能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```
注意:
```java
0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
```

## 解题思想

每天可能存在2个状态，买入股票，卖出股票。
buy[i]表示第i天状态为持股时的最大收益；
sell[i]表示第i天状态为不持股时的最大收益；

则有：
buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee); //以卖出时作为标准扣除手续费

## 解题代码

### Java

```java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[] buy = new int[n];
        int[] sell = new int[n];
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = Math.max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i] - fee);
        }
        return sell[n - 1];
    }
}
```