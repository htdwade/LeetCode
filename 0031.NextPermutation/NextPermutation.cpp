/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return;
		int index = n - 1;
		while (index > 0) {
			if (nums[index - 1] < nums[index])
				break;
			index--;
		}
		if (index == 0) {
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = n - 1; i >= index; i--) {
			if (nums[i] > nums[index - 1]) {
				swap(nums[i], nums[index - 1]);
				break;
			}
		}
		reverse(nums.begin() + index, nums.end());
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1, 2, 3 };
	solution.nextPermutation(nums1);
	for (auto a : nums1)
		cout << a << '\t';
	cout << '\n';
	vector<int> nums2 = { 3, 2, 1 };
	solution.nextPermutation(nums2);
	for (auto a : nums2)
		cout << a << '\t';
	cout << '\n';
	vector<int> nums3 = { 1, 1, 5 };
	solution.nextPermutation(nums3);
	for (auto a : nums3)
		cout << a << '\t';
	cout << '\n';
	return 0;
}