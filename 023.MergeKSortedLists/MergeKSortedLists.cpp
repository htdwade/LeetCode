/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		if (lists.size() == 1)
			return lists[0];
		auto cmp = [](ListNode* const& l1, ListNode* const& l2) {return l1->val > l2->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
		for (auto list : lists)
			if (list)
				q.push(list);
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (!q.empty()) {
			ListNode* t = q.top();
			q.pop();
			cur->next = t;
			cur = cur->next;
			if (t->next)
				q.push(t->next);
		}
		return head->next;
	}

	ListNode* mergeKLists2(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		if (lists.size() == 1)
			return lists[0];
		int mid = lists.size() / 2;
		vector<ListNode*> left = vector<ListNode*>(lists.begin(), lists.begin() + mid);
		vector<ListNode*> right = vector<ListNode*>(lists.begin() + mid, lists.end());
		ListNode* l1 = mergeKLists(left);
		ListNode* l2 = mergeKLists(right);
		ListNode* head = merge2Lists(l1, l2);
		return head;
	}

private:
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return head->next;
	}
};

int main()
{
	Solution solution;
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(4);
	ListNode* p3 = new ListNode(5);
	ListNode* p4 = new ListNode(1);
	ListNode* p5 = new ListNode(3);
	ListNode* p6 = new ListNode(4);
	ListNode* p7 = new ListNode(2);
	ListNode* p8 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	p4->next = p5;
	p5->next = p6;
	p7->next = p8;
	vector<ListNode*> lists = { p1, p4, p7 };
	ListNode* head = solution.mergeKLists(lists);
	while (head) {
		cout << head->val << '\t';
		head = head->next;
	}
	return 0;
}