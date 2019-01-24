/*

Write a program to find the node at which the intersection of two singly linked lists begins.

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
			return nullptr;
		ListNode* p1 = headA;
		ListNode* p2 = headB;
		while (p1 != p2) {
			p1 = (p1 == nullptr) ? headB : p1->next;
			p2 = (p2 == nullptr) ? headA : p2->next;
		}
		return p1;
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
	ListNode* p6 = new ListNode(6);
	ListNode* p7 = new ListNode(7);
	p1->next = p2;
	p2->next = p3;
	p3->next = p6;
	p6->next = p7;
	p4->next = p5;
	p5->next = p6;
	ListNode* headA = p1;
	ListNode* headB = p4;
	cout << solution.getIntersectionNode(headA, headB)->val << endl;
	return 0;
}
