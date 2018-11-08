/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty())
			return nullptr;
		return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

private:
	TreeNode* dfs(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
		if (inStart > inEnd || postStart > postEnd)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[postEnd]);
		int rootIndex = 0;
		for (int i = inStart; i <= inEnd; i++)
			if (inorder[i] == postorder[postEnd]) {
				rootIndex = i;
				break;
			}
		int k = rootIndex - inStart;
		root->left = dfs(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + k - 1);
		root->right = dfs(inorder, rootIndex + 1, inEnd, postorder, postStart + k, postEnd - 1);
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
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	TreeNode* root = solution.buildTree(inorder, postorder);
	printTree(root);
	return 0;
}