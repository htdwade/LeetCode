/*

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//[left...right)
		int left = 0, right = 0;
		int sum = 0;
		int minLen = INT_MAX;
		while (right < nums.size()) {
			sum += nums[right++];
			while (sum >= s) {
				minLen = min(minLen, right - left);
				sum -= nums[left++];
			}
		}
		return minLen == INT_MAX ? 0 : minLen;
	}
};

int main()
{
	Solution solution;
	int s = 7;
	vector<int> nums = { 2,3,1,2,4,3 };
	cout << solution.minSubArrayLen(s, nums) << endl;
	return 0;
}