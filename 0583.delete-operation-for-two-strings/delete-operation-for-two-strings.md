# 583. 两个字符串的删除操作

## 题目描述

给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

 

示例：
```java
输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
```

提示：

* 给定单词的长度不超过500。
* 给定单词中的字符只含有小写字母。

## 解题思路

问题转化为求最长公共子序列问题，删除操作的最小步数 = 两个字符串的长度和 - 2倍的最长公共子序列长度。
设dp[i][j]表示word1的前i个字符和word2的前j个字符的最长公共子序列长度，则有：
* 若word1[i - 1] == word2[j - 1]，则dp[i][j] = dp[i - 1][j - 1] + 1；
* 若word2[i - 1] != word2[j - 1]，则dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]).

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
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1.charAt(i - 1) == word2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m + n - 2 * dp[m][n];
    }
}
```