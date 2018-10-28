/*

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == nullptr)
			return vector<string>();
		vector<string> res;
		string path = to_string(root->val);
		dfs(res, path, root);
		return res;
	}

private:
	void dfs(vector<string>& res, string path, TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) {
			res.push_back(path);
			return;
		}
		if (root->left)
			dfs(res, path + "->" + to_string(root->left->val), root->left);
		if (root->right)
			dfs(res, path + "->" + to_string(root->right->val), root->right);
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p5 = new TreeNode(5);
	p1->left = p2;
	p1->right = p3;
	p2->right = p5;
	vector<string> res = solution.binaryTreePaths(p1);
	for (auto s : res)
		cout << s << endl;
	return 0;
}