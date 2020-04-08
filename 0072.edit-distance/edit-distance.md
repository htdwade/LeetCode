# 72. 编辑距离

## 题目描述

给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

1. 插入一个字符
2. 删除一个字符
3. 替换一个字符
 

示例 1：
```java
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

示例 2：
```java
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```

## 解题思路

设dp[i][j]表示word1的前i个字符转换成word2的前j个字符所需要的最少操作数，则有：
* 若word1[i - 1] == word2[j - 1]，则dp[i][j] = dp[i - 1][j - 1]；
* 若word2[i - 1] != word2[j - 1]，则dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1.

## 解题代码

### Java

```java
class Solution {
    public int minDistance(String word1, String word2) {
        if(word1 == null || word2 == null)
            return 0;
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++)
            dp[i][0] = i;
        for(int i = 1; i<= n; i++)
            dp[0][i] = i;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i -1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[m][n];
    }
}
```