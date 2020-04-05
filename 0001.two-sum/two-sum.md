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

使用哈希表。遍历数组 nums，i 为当前下标，每个值都判断map中是否存在 target-nums[i] 的 key 值，如果存在则找到了这两个值，如果不存在则将当前的 (nums[i],i) 存入 map 中，继续遍历直到找到为止。

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