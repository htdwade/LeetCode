/*

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() <= 0 || k <= 0)
			return;
		int n = nums.size();
		int m = k % n;
		reverse(nums, 0, n - m - 1);
		reverse(nums, n - m, n - 1);
		reverse(nums, 0, n - 1);
	}

	void reverse(vector<int>& nums, int left, int right) {
		while (left < right) {
			swap(nums[left], nums[right]);
			left++;
			right--;
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1,2,3,4,5,6,7 };
	int k1 = 3;
	vector<int> nums2 = { -1,-100,3,99 };
	int k2 = 2;
	solution.rotate(nums1, k1);
	for (auto a : nums1)
		cout << a << '\t';
	cout << '\n';
	solution.rotate(nums2, k2);
	for (auto b : nums2)
		cout << b << '\t';
	return 0;
}
