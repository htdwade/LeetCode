# 309. 最佳买卖股票时机含冷冻期

## 题目描述

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:
```java
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

## 解题思路

每天可能存在3个状态，买入股票，卖出股票，冷冻期。
buy[i]表示第i天状态为持股时的最大收益；
sell[i]表示第i天状态为不持股时的最大收益；
rest[i]表示第i天状态为冷冻期时的最大收益；

![](https://raw.githubusercontent.com/htdwade/PicBed/master/img/20200330060638.png)
则有：
buy[i] = max(rest[i-1] - prices[i], buy[i - 1])
sell[i] = max(buy[i - 1] + prices[i], sell[i - 1])
rest[i] = sell[i - 1]

## 解题代码

### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2)
            return 0;
        int n = prices.length;
        int[] buy = new int[n];
        int[] sell = new int[n];
        int[] rest = new int[n];
        buy[0] = -prices[0];
        for(int i = 1; i < n; i++) {
            buy[i] = Math.max(rest[i - 1] - prices[i], buy[i - 1]);
            sell[i] = Math.max(buy[i - 1] + prices[i], sell[i - 1]);
            rest[i] = sell[i - 1];
        }
        return Math.max(sell[n - 1], rest[n - 1]);
    }
}
```