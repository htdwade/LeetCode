/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that 
at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//Two Pointers
	int findDuplicate(vector<int>& nums) {
		int fast = nums[nums[0]], slow = nums[0];
		while (fast != slow) {
			fast = nums[nums[fast]];
			slow = nums[slow];
		}
		slow = 0;
		while (fast != slow) {
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
	}

	//Binary Search
	int findDuplicate2(vector<int>& nums) {
		int start = 1, end = nums.size() - 1;
		while (start < end) {
			int count = 0;
			int mid = start + (end - start) / 2;
			for (auto num : nums)
				if (num <= mid)
					count++;
			if (count <= mid)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1,3,4,2,2 };
	vector<int> nums2 = { 3,1,3,4,2 };
	cout << solution.findDuplicate(nums1) << endl;
	cout << solution.findDuplicate2(nums2) << endl;
	return 0;
}