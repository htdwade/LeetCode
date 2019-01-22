/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int n = s.size();
		vector<int> dp(n + 1, 0);
		dp[n] = 1;
		dp[n - 1] = s[n - 1] == '0' ? 0 : 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '0')
				continue;
			dp[i] = dp[i + 1];
			int num = (s[i] - '0') * 10 + s[i + 1] - '0';
			if (num <= 26)
				dp[i] += dp[i + 2];
		}
		return dp[0];
	}
};

int main()
{
	Solution solution;
	cout << solution.numDecodings("12") << endl;
	cout << solution.numDecodings("226") << endl;
	return 0;
}
