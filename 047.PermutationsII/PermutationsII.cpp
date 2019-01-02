/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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
		unordered_set<int> s;
		for (int i = index; i < nums.size(); i++) {
			if (s.find(nums[i]) != s.end())
				continue;
			s.insert(nums[i]);
			swap(nums[index], nums[i]);
			helper(res, nums, index + 1);
			swap(nums[index], nums[i]);
		}

	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1,1,2 };
	vector<vector<int>> res = solution.permuteUnique(nums);
	for (auto v : res) {
		for (auto x : v)
			cout << x << '\t';
		cout << '\n';
	}
	return 0;
}