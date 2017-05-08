'''

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

'''

class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        cur = head
        extra = 0
        while l1 or l2 or extra :
            sum = (l1.val if l1 else 0) + (l2.val if l2 else 0) + extra
            extra = sum // 10
            temp = ListNode(sum % 10)
            cur.next = temp
            cur = cur.next
            if l1 :
                l1 = l1.next
            if l2 :
                l2 = l2.next
        return head.next

if __name__ == '__main__' :
    a , a.next , a.next.next = ListNode(2) , ListNode(4) , ListNode(3)
    b , b.next , b.next.next = ListNode(5) , ListNode(6) , ListNode(4)
    solution = Solution()
    head = solution.addTwoNumbers(a,b)
    print(head.val,head.next.val,head.next.next.val)
