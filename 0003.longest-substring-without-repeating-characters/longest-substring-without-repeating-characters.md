# 3. 无重复字符的最长子串

## 题目描述

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
```java
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```
示例 2:
```java
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```
示例 3:
```java
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

## 解题思路

滑动窗口思想。利用 HashMap 将字符存储在当前窗口[start...i]中，遍历字符串，start 用来维护最长不重复子串的左边界，i 用来遍历字符串及充当右边界，同时更新 s[i] 在 HashMap 中的值。如果 s[i] 已经在 HashMap 中，且s[i]的hash值大于等于start，即 s[i] 在之前维护的最长不重复子串内，则维护左指针到hash[s[i]] + 1。

## 解题代码

### Java

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hash = new HashMap<>();
        int res = 0;
        int start = 0;
        // [start...i]
        for(int i = 0; i < s.length(); i++) {
            if(hash.containsKey(s.charAt(i)))
                start = Math.max(start, hash.get(s.charAt(i)) + 1);
            hash.put(s.charAt(i), i);
            res = Math.max(res, i - start + 1);
        }
        return res;
    }
}
```

