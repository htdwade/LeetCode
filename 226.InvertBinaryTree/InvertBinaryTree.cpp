/*

Invert a binary tree.

Example:

Input:

	 4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

	 4
   /   \
  7     2
 / \   / \
9   6 3   1

Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew),
but you can’t invert a binary tree on a whiteboard so f*** off.

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
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
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

void preorderPrint(TreeNode* root) {
	if (root) {
		cout << root->val << '\t';
		preorderPrint(root->left);
		preorderPrint(root->right);
	}
}

int main()
{
	Solution solution;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	preorderPrint(root);
	cout << "\n";
	TreeNode* newRoot = solution.invertTree(root);
	preorderPrint(newRoot);
	return 0;
}