# 40. 组合总和 II

## 题目描述

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

* 所有数字（包括目标数）都是正整数。
* 解集不能包含重复的组合。 

示例 1:
```java
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```
示例 2:
```java
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
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
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        helper(res, temp, candidates, target, 0);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> temp, int[] candidates, int target, int start) {
        if(target < 0)
            return;
        if(target == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = start; i < candidates.length; i++) {
            if(i > start && candidates[i] == candidates[i - 1])
                continue;
            temp.add(candidates[i]);
            helper(res, temp, candidates, target - candidates[i], i + 1);
            temp.remove(temp.size() - 1);
        }
    }
}
```