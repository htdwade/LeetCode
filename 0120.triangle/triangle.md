# 120. 三角形最小路径和

## 题目描述

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：
```java
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

## 解题思路

自底向上的动态规划。dp[i][j]表示从n-1层到第i层经过点(i,j)的最小路径和，则有:
dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j].
因为第i层的值只于第i+1层的两个值相关，所以可以压缩空间为：
dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]. 
//dp[j]使用的时候默认是上一层的，赋值之后变成当前层

## 解题代码

### Java

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.size() == 0)
            return 0;
        int[] dp = new int[triangle.size() + 1];
        for(int i = triangle.size() - 1; i >= 0; i--) {
            List<Integer> col = triangle.get(i);
            for(int j = 0; j < col.size(); j ++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + col.get(j);
            }
        }
        return dp[0];
    }
}
```