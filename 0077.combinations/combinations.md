# 77. 组合

## 题目描述

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:
```java
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

## 解题思路

回溯法。回溯算法的框架为：
```java
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

for 选择 in 选择列表:
    做选择
    backtrack(路径, 选择列表)
    撤销选择
```

## 解题代码

### Java

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        helper(res, temp, n, k, 1);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> temp, int n, int k, int start) {
        if(k == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = start; i <= n; i++) {
            temp.add(i);
            helper(res, temp, n, k - 1, i + 1);
            temp.remove(temp.size() - 1);
        }
    }
}
```