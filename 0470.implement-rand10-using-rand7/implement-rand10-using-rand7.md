# 470. 用 Rand7() 实现 Rand10()

## 题目描述

已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。


示例 1:
```java
输入: 1
输出: [7]
```
示例 2:
```java
输入: 2
输出: [8,4]
```
示例 3:
```java
输入: 3
输出: [8,1,10]
```

## 解题思路

用拒绝采样的方法实现 Rand10()。在拒绝采样中，如果生成的随机数满足要求，那么就返回该随机数，否则会不断生成直到一个满足要求的随机数为止。若我们调用两次 Rand7()，那么可以生成 [1, 49] 之间的随机整数，我们只用到其中的 40 个，用来实现 Rand10()，而拒绝剩下的 9 个数。如图所示：
![](https://pic.leetcode-cn.com/Figures/470/rejectionSamplingTable.png)

两次调用rand7()会得到行和列索引，它们对应于上表中的唯一位置，每个位置出现的概率是一样的。

## 解题代码

### Java

```java
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int res;
        do {
            int row = rand7();
            int col = rand7();
            res = (row - 1) * 7 + col;
        }while(res > 40);
        return res % 10 + 1;
    }
}
```


