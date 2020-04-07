# 47. 全排列 II

## 题目描述

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:
```java
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
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
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        Arrays.sort(nums);
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
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) //used[i-1]=false说明回溯到了同一层
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