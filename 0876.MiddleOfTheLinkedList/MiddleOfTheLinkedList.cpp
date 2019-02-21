/*

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

Note:

The number of nodes in the given list will be between 1 and 100.

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
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
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
	ListNode* middle = solution.middleNode(head);
	cout << middle->val << endl;
	return 0;
}