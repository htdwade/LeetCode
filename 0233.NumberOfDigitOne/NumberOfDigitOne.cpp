/*

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than 
or equal to n.

Example:

Input: 13
Output: 6
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0)
			return 0;
		int  count = 0;
		long long factor = 1;
		while (n / factor) {
			long long cur = (n / factor) % 10;
			long long high = (n / factor) / 10;
			long long low = n % factor;
			if (cur == 0)
				count += high * factor;
			else if (cur == 1)
				count += high * factor + low + 1;
			else
				count += (high + 1) * factor;
			factor *= 10;
		}
		return count;
	}

	int countDigitOne2(int n) {
		if (n <= 0)
			return 0;
		int  count = 0;
		for (long long i = 1; i <= n; i *= 10) {
			long long a = n / i, b = n % i;
			count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
		}
		return count;
	}
};

int main()
{
	Solution solution;
	cout << solution.countDigitOne(13) << endl;
	cout << solution.countDigitOne2(13) << endl;
	return 0;
}
