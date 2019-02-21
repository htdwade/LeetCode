/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		helper(res, subset, nums, 0);
		return res;
	}

private:
	void helper(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
		res.push_back(subset);
		for (int i = start; i < nums.size(); i++) {
			if (i > start && nums[i] == nums[i - 1])
				continue;
			subset.push_back(nums[i]);
			helper(res, subset, nums, i + 1);
			subset.pop_back();
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> res = solution.subsetsWithDup(nums);
	for (auto t : res) {
		for (auto a : t)
			cout << a << '\t';
		cout << endl;
	}
	return 0;
}