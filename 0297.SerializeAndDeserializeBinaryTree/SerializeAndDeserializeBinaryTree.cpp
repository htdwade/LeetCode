/*

Serialization is the process of converting a data structure or object into a sequence of bits so that 
it can be stored in a file or memory buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree 
can be serialized to a string and this string can be deserialized to the original tree structure.

Example:

You may serialize the following tree:

	1
   / \
  2   3
	 / \
	4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		serializeCore(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty())
			return nullptr;
		queue<string> node;
		string s = "";
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == ',') {
				node.push(s);
				s.clear();
			}
			else
				s += data[i];
		}
		TreeNode* root = deserializeCore(node);
		return root;
	}

private:
	void serializeCore(TreeNode* root, string& res) {
		if (root == nullptr) {
			res += "$,";
			return;
		}
		res += to_string(root->val) + ',';
		serializeCore(root->left, res);
		serializeCore(root->right, res);
	}

	TreeNode* deserializeCore(queue<string>& node) {
		if (node.empty())
			return nullptr;
		string s = node.front();
		node.pop();
		if (s == "$")
			return nullptr;
		TreeNode* root = new TreeNode(stoi(s));
		root->left = deserializeCore(node);
		root->right = deserializeCore(node);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
	Codec codec;
	TreeNode* root = createBinaryTree();
	cout << "二叉树创建完成" << endl;
	preorderPrint(root);
	cout << "\n\n";
	TreeNode* newRoot = codec.deserialize(codec.serialize(root));
	preorderPrint(root);
	return 0;
}