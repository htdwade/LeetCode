# 1. 两数之和

## 题目描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

```java
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 解题思路

使用哈希表。在进行迭代并将元素插入到表中的同时，检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。

## 解题代码

### Java

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hash = new HashMap<>();
        int[] res = new int[2];
        for(int i = 0; i < nums.length; i++){
            int numToFind = target - nums[i];
            if(hash.containsKey(numToFind)){
                res[0] = hash.get(numToFind);
                res[1] = i;
                break;
            }
            hash.put(nums[i], i);
        }
        return res;
    }
}
```