/*

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())
			return "";
		auto cmp = [](const int& a, const int& b) {return to_string(a) + to_string(b) > to_string(b) + to_string(a); };
		sort(nums.begin(), nums.end(), cmp);
		string res = "";
		for (auto a : nums)
			res += to_string(a);
		while (res[0] == '0' && res.size() > 1)
			res = res.substr(1);
		return res;
	}
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 10,2 };
	cout << solution.largestNumber(nums1) << endl;
	vector<int> nums2 = { 3,30,34,5,9 };
	cout << solution.largestNumber(nums2) << endl;
	return 0;
}
