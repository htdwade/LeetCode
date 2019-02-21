/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty())
			return "";
		int m = num1.size();
		int n = num2.size();
		vector<int> res(m + n, 0);
		string s = "";
		for (int i = m - 1; i >= 0; i--)
			for (int j = n - 1; j >= 0; j--) {
				int tmp = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
				res[i + j + 1] = tmp % 10;
				res[i + j] += tmp / 10;
			}
		int index = 0;
		while (index < m + n && res[index] == 0)
			index++;
		for (int k = index; k < m + n; k++)
			s += res[k] + '0';
		return s.size() ? s : "0";
	}
};

int main()
{
	Solution solution;
	cout << solution.multiply("2", "3") << endl;
	cout << solution.multiply("123", "456") << endl;
	return 0;
}