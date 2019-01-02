/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> subset;
		helper(res, subset, 1, n, k);
		return res;
	}

private:
	void helper(vector<vector<int>>& res, vector<int>& subset, int start, int n, int k) {
		if (subset.size() == k) {
			res.push_back(subset);
			return;
		}
		for (int i = start; i <= n; i++) {
			subset.push_back(i);
			helper(res, subset, i + 1, n, k);
			subset.pop_back();
		}
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> res = solution.combine(4, 2);
	for (auto t : res) {
		for (auto a : t)
			cout << a << '\t';
		cout << endl;
	}
	return 0;
}