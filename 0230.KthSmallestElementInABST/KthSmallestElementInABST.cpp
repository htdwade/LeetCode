/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest 
frequently? How would you optimize the kthSmallest routine?

*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int res = 0;
		dfs(root, k, res);
		return res;
	}

private:
	void dfs(TreeNode* root, int& k, int& res) {
		if (root == nullptr)
			return;
		dfs(root->left, k, res);
		--k;
		if (k == 0) {
			res = root->val;
			return;
		}
		dfs(root->right, k, res);
	}
};

int main()
{
	Solution solution;
	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(2);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(4);
	p3->left = p1;
	p3->right = p4;
	p1->right = p2;
	TreeNode* root = p3;
	cout << solution.kthSmallest(root, 1) << endl;
	return 0;
}
