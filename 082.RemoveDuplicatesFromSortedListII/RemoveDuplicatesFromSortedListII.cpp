/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only 
distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3

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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		while (cur != nullptr) {
			while (cur->next != nullptr && cur->val == cur->next->val)
				cur = cur->next;
			if (pre->next == cur)
				pre = pre->next;
			else
				pre->next = cur->next;
			cur = cur->next;
		}
		return dummy->next;
	}
};

void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p -> val << '\t';
		p = p -> next;
	}
	cout << '\n';
}

int main()
{
	Solution solution;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(4);
	ListNode* p6 = new ListNode(4);
	ListNode* p7 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	ListNode* head = p1;
	printList(head);
	ListNode* newHead = solution.deleteDuplicates(head);
	printList(newHead);
	return 0;
}