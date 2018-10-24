/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
return its minimum depth = 2.

*/


#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//dfs
	int minDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		if (!left || !right)
			return left + right + 1;
		return min(left, right) + 1;
	}

	//bfs
	int minDepth2(TreeNode* root) {
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		while (q.size()) {
			int n = q.size();
			level++;
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				if (t->left == nullptr && t->right == nullptr)
					return level;
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
				q.pop();
			}
		}
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
	cout << solution.minDepth2(root) << endl;
	return 0;
}