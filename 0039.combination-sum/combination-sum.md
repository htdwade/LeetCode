# 39. 组合总和

## 题目描述

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

* 所有数字（包括 target）都是正整数。
* 解集不能包含重复的组合。 

示例 1:
```java
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
```
示例 2:
```java
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
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
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
       List<List<Integer>> res = new ArrayList<>();
       List<Integer> temp = new ArrayList<>();
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
            temp.add(candidates[i]);
            helper(res, temp, candidates, target - candidates[i], i);
            temp.remove(temp.size() - 1);
        }
    }
}
```