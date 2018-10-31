/*

Given a non-empty integer array, find the minimum number of moves required to make all 
array elements equal, where a move is incrementing a selected element by 1 or decrementing 
a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0, j = nums.size() - 1;
		int count = 0;
		while (i < j) {
			count += nums[j] - nums[i];
			i++;
			j--;
		}
		return count;
	}
};

int main()
{	
	Solution solution;
	vector<int> nums = { 1, 2, 3 };
	cout << solution.minMoves2(nums) << endl;
	return 0;
}