# 398. 随机数索引

## 题目描述

给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:
```java
int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);
```

## 解题思路

蓄水池抽样问题。
* 先取出前 k 个数；
* 从第 k+1 开始，以 $\frac{k}{i}$ 的概率取出这个数，并随机替换掉之前已经取出的 k 个数中的一个。

这样可以保证当数据流有 N 个数据时，不论 N 为多少，每个数被取出的概率都为 $\frac{k}{N}$ 

伪代码如下：
```java
Init a reservoir with the size k
for i = k + 1 to N
     M = random(0, i); //[0...i)
     if (M < k)
         SWAP the Mth value and ith value
end for
```

## 解题代码

### Java

```java
class Solution {
    private int[] nums;
    private Random random;

    public Solution(int[] nums) {
        this.nums = nums;
        random = new Random();
    }
    
    public int pick(int target) {
        int res = -1;
        int index = 1;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == target) {
                int m = random.nextInt(index);
                if(m < 1)
                    res = i;
                index++;
            }
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```