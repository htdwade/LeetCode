# 188. 买卖股票的最佳时机 IV

## 题目描述

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
```java
输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```
示例 2:
```java
输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

## 解题思路

当k大于等于数组长度一半时, 买卖k次就等价于买卖无限次，问题转化为买卖股票的最佳时机II，采用贪心的方法解决。
对于其他的k, 可以采用买卖股票的最佳时机III的方法来解决, 在III中定义了两次买入和卖出时最大收益的变量, 在这里就是k组这样的变量, 即问题IV是对问题III的推广, buy[i]和sell[i]分别表示第i比交易买入和卖出时各自的最大收益。

## 解题代码

### Java

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices == null || prices.length < 2 || k <= 0)
            return 0;
        if(k >= prices.length / 2){
            int maxProfit = 0;
            for(int i = 1; i < prices.length; i++) {
                if(prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            }
            return maxProfit;
        }

        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];
        for(int i = 0; i <= k; i++) {
            buy[i] = Integer.MIN_VALUE;
        }
        for(int i = 0; i < prices.length; i++){
            for(int j = 1; j <= k; j++) {
                buy[j] = Math.max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = Math.max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
}
```