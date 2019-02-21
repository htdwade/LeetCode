/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		if (n < 7)
			return n;
		vector<int> res(n);
		res[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; i++) {
			res[i] = min(min(res[p2] * 2, res[p3] * 3), res[p5] * 5);
			if (res[i] == res[p2] * 2)
				++p2;
			if (res[i] == res[p3] * 3)
				++p3;
			if (res[i] == res[p5] * 5)
				++p5;
		}
		return res[n - 1];
	}
};

int main()
{
	Solution solution;
	cout << solution.nthUglyNumber(10) << endl;
	return 0;
}
