/*

Write a function that takes an unsigned integer and returns the number of '1' bits it has 
(also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011

Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000

*/

#include <iostream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n) {
			n &= n - 1;
			res++;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.hammingWeight(11) << endl;
	cout << solution.hammingWeight(128) << endl;
	return 0;
}