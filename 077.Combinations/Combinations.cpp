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
		vector<int> temp;
		dfs(res, temp, 0, 1, n, k);
		return res;
	}

private:
	void dfs(vector<vector<int>>& res, vector<int>& temp, int count, int start, int n, int k) {
		if (count == k) {
			res.push_back(temp);
			return;
		}
		for (int i = start; i <= n; i++) {
			temp.push_back(i);
			dfs(res, temp, count + 1, i + 1, n, k);
			temp.pop_back();
		}
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> res = solution.combine(4,2);
	for (auto t : res) {
		for (auto a : t)
			cout << a << '\t';
		cout << endl;
	}
	return 0;
}