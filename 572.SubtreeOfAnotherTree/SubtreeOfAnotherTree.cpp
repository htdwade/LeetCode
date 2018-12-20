/*

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values 
with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

	 3
	/ \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:

	 3
	/ \
   4   5
  / \
 1   2
	/
   0
Given tree t:
   4
  / \
 1   2
Return false.

*/

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr || t == nullptr)
			return false;
		return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}

private:
	bool isSame(TreeNode* s, TreeNode* t) {
		if (s == nullptr && t == nullptr)
			return true;
		if (s == nullptr || t == nullptr)
			return false;
		if (s->val != t->val)
			return false;
		return isSame(s->left, t->left) && isSame(s->right, t->right);
	}
};

TreeNode* createBinaryTree() {
	int x;
	cin >> x;
	if (x == -1)
		return nullptr;
	TreeNode* root = new TreeNode(x);
	root->left = createBinaryTree();
	root->right = createBinaryTree();
	return root;
}

int main()
{
	Solution solution;
	TreeNode* s = createBinaryTree();
	cout << "s创建完成" << endl;
	TreeNode* t = createBinaryTree();
	cout << "t创建完成" << endl;
	cout << solution.isSubtree(s, t) << endl;
	return 0;
}