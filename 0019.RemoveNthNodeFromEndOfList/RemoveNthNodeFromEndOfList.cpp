/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr || n <= 0)
			return nullptr;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* fast = head;
		ListNode* slow = dummy;
		for (int i = 0; i < n - 1; i++) {
			fast = fast->next;
			if (fast == nullptr)
				return nullptr;
		}
		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return dummy->next;
	}
};

ListNode* createList() {
	ListNode head(0);
	ListNode* cur = &head;
	int x;
	while (cin >> x) {
		ListNode* temp = new ListNode(x);
		cur->next = temp;
		cur = cur->next;
	}
	return head.next;
}

void printList(ListNode* head) {
	ListNode* p = head;
	while (p) {
		cout << p->val << '\t';
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Solution solution;
	ListNode* head = createList();
	printList(head);
	ListNode* newHead = solution.removeNthFromEnd(head, 2);
	printList(newHead);
	return 0;
}