/*

Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False

*/


#include <iostream>

using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		if (c < 0) return false;
		int i = 0, j = (int)sqrt(c);
		while (i <= j) {
			int sum = i * i + j * j;
			if (sum == c)
				return true;
			else if (sum < c)
				i++;
			else
				j--;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	cout << solution.judgeSquareSum(5) << endl;
	cout << solution.judgeSquareSum(3) << endl;
	return 0;
}