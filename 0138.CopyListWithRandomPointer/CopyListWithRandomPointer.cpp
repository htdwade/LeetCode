/*

A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.

*/

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == nullptr)
			return nullptr;
		//复制节点
		RandomListNode* cur = head;
		while (cur != nullptr) {
			RandomListNode* pNext = cur->next;
			RandomListNode* copy = new RandomListNode(cur->label);
			cur->next = copy;
			copy->next = pNext;
			cur = pNext;
		}
		//复制随机指针
		cur = head;
		while (cur != nullptr) {
			if (cur->random != nullptr)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}
		//拆分
		cur = head;
		RandomListNode* dummy = new RandomListNode(-1);
		RandomListNode* p = dummy;
		while (cur != nullptr) {
			RandomListNode* copy = cur->next;
			cur->next = copy->next;
			cur = cur->next;
			p->next = copy;
			p = p->next;
		}
		return dummy->next;
	}
};

int main()
{
	Solution solution;
	RandomListNode* p1 = new RandomListNode(1);
	RandomListNode* p2 = new RandomListNode(2);
	RandomListNode* p3 = new RandomListNode(3);
	RandomListNode* p4 = new RandomListNode(4);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p1->random = p3;
	p2->random = p4;
	RandomListNode* head = p1;
	RandomListNode* copyHead = solution.copyRandomList(head);
	cout << copyHead->label << endl;
	cout << copyHead->random->label << endl;
	cout << copyHead->next->label << endl;
	cout << copyHead->next->random->label << endl;
	return 0;
}