/*

Given an integer n, generate all structurally unique BST's (binary search trees) that store 
values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3

*/


#include <iostream>
#include <vector>
#include <queue>
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
	 vector<TreeNode*> generateTrees(int n) {
		 if (n <= 0)
			 return vector<TreeNode*>();
		 return dfs(1, n);
	 }

 private:
	 vector<TreeNode*> dfs(int start, int end) {
		 vector<TreeNode*> res;
		 if (start > end) {
			 res.push_back(nullptr);
			 return res;
		 }
		 for (int i = start; i <= end; i++) {
			 vector<TreeNode*> left = dfs(start, i - 1);
			 vector<TreeNode*> right = dfs(i + 1, end);
			 for (auto l : left)
				 for (auto r : right) {
					 TreeNode* root = new TreeNode(i);
					 root->left = l;
					 root->right = r;
					 res.push_back(root);
				 }
		 }
		 return res;
	 }

 };

void levelPrintTree(TreeNode* root) {
	if (root == nullptr)
		return;
	queue<TreeNode*> q;
	q.push(root);
	cout << root->val << '\t';
	while (q.size()) {
		TreeNode* t = q.front();
		q.pop();
		if (t->left && t->right) {
			cout << t->left->val << '\t';
			q.push(t->left);
			cout << t->right->val << '\t';
			q.push(t->right);
			if (t->left->left == nullptr && t->left->right == nullptr && (t->right->left || t->right->right))
				cout << "NULL" << '\t' << "NULL" << '\t';
		}
		else if (t->left) {
			cout << t->left->val << '\t';
			q.push(t->left);
			if (t->left->left || t->left->right)
				cout << "NULL" << '\t';
		}
		else if(t->right){
			cout << "NULL" << '\t';
			cout << t->right->val << '\t';
			q.push(t->right);
		}
	}
	cout << endl;
}

int main()
{
	Solution solution;
	vector<TreeNode*> res = solution.generateTrees(3);
	for (auto t : res)
		levelPrintTree(t);
	return 0;
}