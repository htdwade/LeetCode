/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        while(l1 && l2){
            if(l1 -> val <= l2 -> val){
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else{
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = l1 ? l1 : l2;
        return head.next;
    }
};

ListNode* createList() {
    ListNode head(0);
    ListNode* cur = &head;
    int x;
    while(cin >> x){
        ListNode* temp = new ListNode(x);
        cur -> next = temp;
        cur = cur -> next;
    }
    return head.next;
}

void printList(ListNode* head) {
    ListNode* p = head;
    while(p){
        cout << p -> val << '\t';
        p = p -> next;
    }
}

int main()
{
    Solution solution;
    ListNode* l1 = createList();
    cin.clear();
    cin.sync();
    ListNode* l2 = createList();
    ListNode* head = solution.mergeTwoLists(l1, l2);
    printList(head);
    return 0;
}
