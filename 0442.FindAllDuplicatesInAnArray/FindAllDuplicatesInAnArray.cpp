/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//用负号来记录该位置对应的数是否出现过
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0)
				res.push_back(index + 1);
			nums[index] = -nums[index];
		}
		return res;
	}

	//将数字交换到对应的位置，然后遍历比较是否出现过
	vector<int> findDuplicates2(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] != nums[nums[i] - 1]) 
				swap(nums[i], nums[nums[i] - 1]);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) 
				res.push_back(nums[i]);
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 4,3,2,7,8,2,3,1 };
	vector<int> res1 = solution.findDuplicates(nums1);
	for (auto a : res1)
		cout << a << '\t';
	cout << '\n';
	vector<int> nums2 = { 4,3,2,7,8,2,3,1 };
	vector<int> res2 = solution.findDuplicates2(nums2);
	for (auto b : res2)
		cout << b << '\t';
	return 0;
}