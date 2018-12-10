/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3

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
		ListNode* cur = head;
		while (cur != nullptr) {
			while (cur->next != nullptr && cur->val == cur->next->val) {
				ListNode* temp = cur->next;
				cur->next = temp->next;
				delete temp;
				temp = nullptr;
			}
			cur = cur->next;
		}
		return head;
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
	ListNode* p2 = new ListNode(1);
	ListNode* p3 = new ListNode(2);
	ListNode* p4 = new ListNode(3);
	ListNode* p5 = new ListNode(3);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	ListNode* head = p1;
	printList(head);
	ListNode* newHead = solution.deleteDuplicates(head);
	printList(newHead);
	return 0;
}