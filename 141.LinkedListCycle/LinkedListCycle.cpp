/*

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?


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
	bool hasCycle(ListNode *head) {
		if (head == nullptr)
			return false;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* head = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	//p4->next = p1;
	cout << solution.hasCycle(head) << endl;
	return 0;
}
