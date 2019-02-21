/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7

*/

#include <iostream>
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

private:
	TreeNode* dfs(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[preStart]);
		int rootIndex = 0;
		for (int i = inStart; i <= inEnd; i++)
			if (inorder[i] == preorder[preStart]) {
				rootIndex = i;
				break;
			}
		int k = rootIndex - inStart;
		root->left = dfs(preorder, preStart + 1, preStart + k, inorder, inStart, inStart + k - 1);
		root->right = dfs(preorder, preStart + k + 1, preEnd, inorder, inStart + k + 1, inEnd);
		return root;
	}
};

void printTree(TreeNode* root) {
	if (root == nullptr)
		cout << "NULL" << '\t';
	else {
		cout << root->val << '\t';
		printTree(root->left);
		printTree(root->right);
	}
}

int main()
{
	Solution solution;
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode* root = solution.buildTree(preorder, inorder);
	printTree(root);
	return 0;
}