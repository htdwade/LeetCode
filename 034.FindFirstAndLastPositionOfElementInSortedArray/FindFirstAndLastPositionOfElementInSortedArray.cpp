/*

Given an array of integers nums sorted in ascending order, find the starting and ending position of a 
given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int start = binarySearch(nums, target);
		if (start == nums.size() || nums[start] != target)
			return res;
		res[0] = binarySearch(nums, target);
		res[1] = binarySearch(nums, target + 1) - 1;
		return res;
	}

private:
	int binarySearch(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 5,7,7,8,8,10 };
	vector<int> res1 = solution.searchRange(nums1, 8);
	cout << res1[0] << '\t' << res1[1] << endl;
	vector<int> nums2 = { 5,7,7,8,8,10 };
	vector<int> res2 = solution.searchRange(nums1, 6);
	cout << res2[0] << '\t' << res2[1] << endl;
	return 0;
}
