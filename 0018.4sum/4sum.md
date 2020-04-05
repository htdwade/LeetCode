# 18. 四数之和

## 题目描述

给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：
```java
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

## 解题思路

参考3sum的解法。先数组排序，使用四个指针(a<b<c<d)。固定最小的a和b在左边，c=b+1，d=n-1，移动两个指针求解。

保存nums[a]+nums[b]+nums[c]+nums[d]==target时的解。偏大时d左移，偏小时c右移。c和d相遇时，表示以当前的a和b为最小值的解已经全部求得。b++,进入下一轮循环b循环，当b循环结束后。a++，进入下一轮a循环。

## 解题代码

### Java

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if(nums == null || nums.length < 4)
            return res;
        Arrays.sort(nums);
        int n = nums.length;
        for(int a = 0; a < n - 3; a++){
            if(a > 0 && nums[a] == nums[a - 1])
                continue;
            for(int b = a + 1; b < n - 2; b++) {
                if(b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                int c = b + 1, d = n - 1;
                while(c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target) {
                        res.add(Arrays.asList(nums[a], nums[b], nums[c], nums[d]));
                        while(c < d && nums[c] == nums[c + 1])
                            c++;
                        while(c < d && nums[d] == nums[d - 1])
                            d--;
                        c++;
                        d--;
                    }
                    else if(sum < target)
                        c++;
                    else
                        d--;
                }
            }
        }
        return res;
    }
}
```
