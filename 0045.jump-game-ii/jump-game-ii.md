# 45. 跳跃游戏 II

## 题目描述

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
```java
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```
说明:

假设你总是可以到达数组的最后一个位置。

## 解题思路

贪心算法。每次在可跳范围内选择可以跳的更远的位置，用jumpPos来表示当前能跳的边界，遇到边界步数加1。

## 解题代码

### Java

```java
class Solution {
    public int jump(int[] nums) {
        int maxReach = 0;
        int jumpEnd = 0;
        int count = 0;
        for(int i = 0; i < nums.length - 1; i++) {
            maxReach = Math.max(maxReach, i + nums[i]);
            if(i == jumpEnd) {
                jumpEnd = maxReach;
                count++;
            }
        }
        return count;
    }
}
```