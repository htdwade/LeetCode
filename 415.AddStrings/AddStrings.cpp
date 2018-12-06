/*

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string res;
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		int carry = 0;
		while (i >= 0 || j >= 0 || carry) {
			int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
			res += (sum % 10 + '0');
			carry = sum / 10;
			--i;
			--j;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.addStrings("123", "3123") << endl;
	return 0;
}