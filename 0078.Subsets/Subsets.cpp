/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		helper(res, subset, nums, 0);
		return res;
	}

private:
	void helper(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
		res.push_back(subset);
		for (int i = start; i < nums.size(); i++) {
			subset.push_back(nums[i]);
			helper(res, subset, nums, i + 1);
			subset.pop_back();
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = solution.subsets(nums);
	for (auto t : res) {
		for (auto a : t)
			cout << a << '\t';
		cout << endl;
	}
	return 0;
}