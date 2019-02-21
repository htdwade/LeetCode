/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int res = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (count == 0) {
				res = nums[i];
				count = 1;
			}
			else if (nums[i] == res)
				count++;
			else
				count--;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 3,2,3 };
	vector<int> nums2 = { 2,2,1,1,1,2,2 };
	cout << solution.majorityElement(nums1) << endl;
	cout << solution.majorityElement(nums2) << endl;
	return 0;
}