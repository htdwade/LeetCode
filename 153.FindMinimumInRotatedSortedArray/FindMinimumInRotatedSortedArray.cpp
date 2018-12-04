/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1

Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		while (start < end) {
			if (nums[start] < nums[end])
				return nums[start];
			int mid = start + (end - start) / 2;
			if (nums[mid] >= nums[start])
				start = mid + 1;
			else
				end = mid;
		}
		return nums[start];
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 3, 4, 5, 1, 2 };
	vector<int> nums2 = { 4, 5, 6, 7, 0, 1, 2 };
	cout << solution.findMin(nums1) << endl;
	cout << solution.findMin(nums2) << endl;
	return 0;
}
