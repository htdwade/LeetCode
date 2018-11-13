/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.


*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k < 2)
			return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = dummy->next;
		ListNode* nex = nullptr;
		int count = 0;
		while (cur) {
			count++;
			cur = cur->next;
		}
		while (count >= k) {
			cur = pre->next;
			nex = cur->next;
			for (int i = 1; i < k; i++) {
				cur->next = nex->next;
				nex->next = pre->next;
				pre->next = nex;
				nex = cur->next;
			}
			pre = cur;
			count -= k;
		}
		return dummy->next;
	}
};
int main()
{
	Solution solution;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* head = solution.reverseKGroup(p1, 3);
	while (head) {
		cout << head->val << '\t';
		head = head->next;
	}
	return 0;
}