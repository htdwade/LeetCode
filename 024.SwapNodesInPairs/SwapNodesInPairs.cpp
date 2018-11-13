/*

Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.


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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* nex = head->next;
		head->next = swapPairs(head->next->next);
		nex->next = head;
		return nex;
	}

	ListNode* swapPairs2(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = pre->next;
		ListNode* nex = cur->next;
		while (cur && nex) {
			cur->next = nex->next;
			nex->next = pre->next;
			pre->next = nex;
			pre = cur;
			cur = pre->next;
			if (cur)
				nex = cur->next;
			else
				break;
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
	ListNode* head = solution.swapPairs2(p1);
	while (head) {
		cout << head->val << '\t';
		head = head->next;
	}
	return 0;
}