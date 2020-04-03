# 123. 买卖股票的最佳时机 III

## 题目描述

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
```java
输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```
示例 2:
```java
输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```
示例 3:
```java
输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
```

## 解题思路

利用状态机，每天其实是有四个状态，买入当前价格的股票，以当前价格的股票卖出。第二次买入股票，第二次卖出股票。s0代表初始状态，初始时钱是 0。s1代表第一次买入后当前的钱，s2代表第一次卖出后当前的钱，s3代表第二次买入后当前的钱，s4代表第二次卖出后当前的钱。

只需要更新每天的这四个状态即可。

![](https://raw.githubusercontent.com/htdwade/PicBed/master/img/20200330042838.png)

## 解题代码

### Java

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices == null || prices.length < 2)
            return 0;
        int buy1 = Integer.MIN_VALUE;
        int sell1 = 0;
        int buy2 = Integer.MIN_VALUE;
        int sell2 = 0;
        for(int i = 0; i < prices.length; i++) {
            buy1 = Math.max(buy1, -prices[i]);   
            sell1 = Math.max(sell1, buy1 + prices[i]); 
            buy2 = Math.max(buy2, sell1 - prices[i]); 
            sell2 = Math.max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
}
```