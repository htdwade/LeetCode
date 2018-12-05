/*

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

*/

#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		bool isNegative = false;
		if (n < 0) {
			n = -n;
			isNegative = true;
		}
		double res = myPow(x * x, (unsigned)n >> 1);
		if (n & 0x1 == 1)
			res *= x;
		return isNegative ? 1.0 / res : res;
	}
};

int main()
{
	Solution solution;
	cout << solution.myPow(2.00000, 10) << endl;
	cout << solution.myPow(2.10000, 3) << endl;
	cout << solution.myPow(2.00000, -2) << endl;
	return 0;
}