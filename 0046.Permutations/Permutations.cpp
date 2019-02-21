/*

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		helper(res, nums, 0);
		return res;
	}

private:
	void helper(vector<vector<int>>& res, vector<int>& nums, int index) {
		if (index == nums.size()) {
			res.push_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); i++) {
			swap(nums[index], nums[i]);
			helper(res, nums, index + 1);
			swap(nums[index], nums[i]);
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = solution.permute(nums);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}