/*

Given a non-empty array of integers, every element appears three times except for one, 
which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3

Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//  a b
	//0 0 0
	//1 x 0
	//2 0 x
	//3 0 0
	int singleNumber(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto x : nums) {
			a = (a ^ x) & ~b;
			b = (b ^ x) & ~a;
		}
		return a;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 2,2,3,2 };
	cout << solution.singleNumber(nums1) << endl;
	vector<int> nums2 = { 0,1,0,1,0,1,99 };
	cout << solution.singleNumber(nums2) << endl;
	return 0;
}
