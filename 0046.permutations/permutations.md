# 46. 全排列

## 题目描述

给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
```java
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        helper(res, temp, used, nums);
        return res;
    }

    private void helper(List<List<Integer>> res, List<Integer> temp, boolean[] used, int[] nums) {
        if(temp.size() == nums.length) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for(int i = 0; i < nums.length; i++) {
            if(used[i])
                continue;
            temp.add(nums[i]);
            used[i] = true;
            helper(res, temp, used, nums);
            temp.remove(temp.size() - 1);
            used[i] = false;
        }
    }
}
```