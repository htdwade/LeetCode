# 382. 链表随机节点

## 题目描述

给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

示例:
```java
// 初始化一个单链表 [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
solution.getRandom();
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
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {

    private ListNode head;
    private Random random;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
        this.random = new Random();
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int res = head.val;
        ListNode cur = head.next;     
        int i = 2;
        while(cur != null) {
            int m = random.nextInt(i);//[0..i)
            if(m < 1)
                res = cur.val;
            cur = cur.next;
            i++;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```
