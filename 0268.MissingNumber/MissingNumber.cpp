/*

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 异或，a^b^b = a
	int missingNumber(vector<int>& nums) {
		int res = nums.size();
		for (int i = 0; i < nums.size(); i++)
			res = res ^ i ^ nums[i];
		return res;
	}

	// n*(n+1)/ 2 - sum
	int missingNumber2(vector<int>& nums) {
		int len = nums.size();
		long long n = len * (len + 1) / 2;
		long long sum = 0;
		for(int i = 0; i < nums.size(); i++)
			sum += nums[i];
		return n - sum;
	}

	// binarysearch
	int missingNumber3(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size();
		while(left < right){
			int mid = left + (right - left) / 2;
			if(nums[mid] > mid)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}

};

int main()
{
	Solution solution;
	vector<int> nums1 = { 3,0,1 };
	vector<int> nums2 = { 9,6,4,2,3,5,7,0,1 };
	cout << solution.missingNumber(nums1) << endl;
	cout << solution.missingNumber(nums2) << endl;
	cout << solution.missingNumber2(nums1) << endl;
	cout << solution.missingNumber2(nums2) << endl;
	cout << solution.missingNumber3(nums1) << endl;
	cout << solution.missingNumber3(nums2) << endl;
 	return 0;
}
