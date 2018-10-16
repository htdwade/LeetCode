/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() == 0)
			return;
		int index = 0;
		for (auto a : nums)
			if (a != 0)
				nums[index++] = a;
		while (index < nums.size())
			nums[index++] = 0;
	}

	void moveZeroes2(vector<int>& nums) {
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i])
				swap(nums[i], nums[index++]);
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 0,1,0,3,12 };
	cout << "调用前:" << endl;
	for (auto a : nums)
		cout << a << '\t';
	solution.moveZeroes2(nums);
	cout << '\n' << "调用后:" << endl;
	for (auto a : nums)
		cout << a << '\t';
	return 0;
}
