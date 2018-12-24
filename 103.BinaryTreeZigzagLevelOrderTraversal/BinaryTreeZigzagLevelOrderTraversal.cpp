/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		bool leftToRight = true;
		while (!q.empty()) {
			int n = q.size();
			vector<int> level(n);
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				q.pop();
				if (leftToRight)
					level[i] = t->val;
				else
					level[n - 1 - i] = t->val;
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
			res.push_back(level);
			leftToRight = !leftToRight;
		}
		return res;
	}
};

TreeNode* createBinaryTree() {
	int x;
	cin >> x;
	if (x == 0)
		return nullptr;
	TreeNode* root = new TreeNode(x);
	root->left = createBinaryTree();
	root->right = createBinaryTree();
	return root;
}

int main()
{
	Solution solution;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	vector<vector<int>> res = solution.zigzagLevelOrder(root);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}