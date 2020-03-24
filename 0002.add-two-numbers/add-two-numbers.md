# 2. 两数相加

## 题目描述

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
```java
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

## 解题思想

模拟竖式加法，注意进位问题。

## 解题代码

### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int extra = 0;
        while(l1 != nullptr || l2 != nullptr || extra != 0) {
            int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + extra;
            extra = sum / 10;
            cur -> next = new ListNode(sum % 10);
            cur = cur -> next;
            if(l1 != nullptr)
                l1 = l1 -> next;
            if(l2 != nullptr)
                l2 = l2 -> next;
        }
        return dummy -> next;
    }
};
```

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        int extra = 0;
        while(l1 != null || l2 != null || extra != 0) {
            int sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + extra;
            extra = sum / 10;
            cur.next = new ListNode(sum % 10);
            cur = cur.next;
            if(l1 != null)
                l1 = l1.next;
            if(l2 != null)
                l2 = l2.next;
        }
        return dummy.next;
    }
}
```
