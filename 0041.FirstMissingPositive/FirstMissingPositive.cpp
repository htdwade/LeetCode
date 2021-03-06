/*

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int j = 0; j < n; j++)
			if (nums[j] != j + 1)
				return j + 1;
		return n + 1;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1,2,0 };
	vector<int> nums2 = { 3,4,-1,1 };
	vector<int> nums3 = { 7,8,9,11,12 };
	cout << solution.firstMissingPositive(nums1) << endl;
	cout << solution.firstMissingPositive(nums2) << endl;
	cout << solution.firstMissingPositive(nums3) << endl;
	return 0;
}