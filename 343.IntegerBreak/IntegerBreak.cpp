/*

Given a positive integer n, break it into the sum of at least two positive integers and maximize the product 
of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		if (n < 2)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		int res = 1;
		while (n > 4) {
			res *= 3;
			n -= 3;
		}
		res *= n;
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.integerBreak(2) << endl;
	cout << solution.integerBreak(10) << endl;
 	return 0;
}
