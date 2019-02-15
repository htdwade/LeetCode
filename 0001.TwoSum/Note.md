## 题目描述

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

### 示例:
```cpp
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```

## 解题思想
将数组中各数下标存入hash表中，从左往右扫描数组，对每一个数K，搜素target-K在hash表中是否存在。

## 解题代码
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int numToFind = target - nums[i];
            if(hash.find(numToFind) != hash.end()){
                res.push_back(hash[numToFind]);
                res.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
```