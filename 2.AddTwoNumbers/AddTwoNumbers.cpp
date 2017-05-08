/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        int extra = 0;
        while (l1 || l2 || extra ) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head.next;
    }
};

ListNode* createList() {
    ListNode head(0);
    ListNode* cur = &head;
    int x;
    while(cin >> x){
        ListNode* temp = new ListNode(x);
        cur->next = temp;
        cur = cur->next;
    }
    return head.next;
}

void printList(ListNode* head) {
    ListNode* p = head;
    while(p){
        cout << p->val << '\t';
        p = p->next;
    }
}

int main()
{
    ListNode* l1 = createList();
    cin.clear();//更改cin的状态标示符
    cin.sync();//清除缓存区的数据流
    ListNode* l2 = createList();
    Solution solution;
    ListNode* head = solution.addTwoNumbers(l1,l2);
    printList(head);
    return 0;
}
