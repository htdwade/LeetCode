# 516. 最长回文子序列

## 题目描述

给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

示例 1:
```java
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。
```

示例 2:
```java
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。
```

## 解题思路

在子串 s[i..j] 中，最长回文子序列的长度设为 dp[i][j]，则有：
```java
if (s[i] == s[j])
    // 它俩一定在最长回文子序列中
    dp[i][j] = dp[i + 1][j - 1] + 2;
else
    // s[i+1..j] 和 s[i..j-1] 谁的回文子序列更长？
    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
```
所求字符串的最长回文序列长度即为dp[0][n-1]，因为计算dp[i][j]需要用到dp[i+1][j]，所以i从后往前遍历。

## 解题代码

### Java

```java
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s.charAt(i) == s.charAt(j))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
```
