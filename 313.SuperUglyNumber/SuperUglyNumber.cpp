/*

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
			 super ugly numbers given primes = [2,7,13,19] of size 4.

Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res(n, INT_MAX);
		vector<int> index(primes.size(), 0);
		res[0] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < primes.size(); j++)
				res[i] = min(res[i], primes[j] * res[index[j]]);
			for (int j = 0; j < primes.size(); j++)
				if (res[i] == primes[j] * res[index[j]])
					index[j]++;
		}
		return res[n - 1];
	}
};

int main()
{
	Solution solution;
	vector<int> primes = { 2,7,13,19 };
	cout << solution.nthSuperUglyNumber(12, primes) << endl;
	return 0;
}
