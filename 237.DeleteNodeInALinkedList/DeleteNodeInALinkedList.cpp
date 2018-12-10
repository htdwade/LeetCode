/*

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:

	4 -> 5 -> 1 -> 9
Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list
			 should become 4 -> 1 -> 9 after calling your function.

Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list
			 should become 4 -> 5 -> 9 after calling your function.

Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.

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
	void deleteNode(ListNode* node) {
		ListNode* temp = node->next;
		node->val = temp->val;
		node->next = temp->next;
		delete temp;
		temp = nullptr;
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
	ListNode* p1 = new ListNode(4);
	ListNode* p2 = new ListNode(5);
	ListNode* p3 = new ListNode(1);
	ListNode* p4 = new ListNode(9);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	ListNode* head = p1;
	printList(head);
	solution.deleteNode(p3);
	printList(head);
	return 0;
}