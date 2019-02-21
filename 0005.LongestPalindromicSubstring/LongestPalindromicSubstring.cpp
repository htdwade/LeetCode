/*

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//DP
	string longestPalindrome1(string s) {
		if (s.empty())
			return "";
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int start = 0;
		int maxLen = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++) {
				if (i - j < 2)
					dp[j][i] = (s[i] == s[j]);
				else
					dp[j][i] = (s[i] == s[j]) && dp[j + 1][i - 1];
				if (dp[j][i] && i - j + 1 > maxLen) {
					start = j;
					maxLen = i - j + 1;
				}
			}
		return s.substr(start, maxLen);
	}

	//中心扩展
	string longestPalindrome2(string s) {
		if (s.empty())
			return "";
		int n = s.size();
		int start = 0;
		int maxLen = 0;
		for (int i = 0; i < n; i++) {
			//奇数扩展
			for (int j = 0; i - j >= 0 && i + j < n; j++) {
				if (s[i - j] != s[i + j])
					break;
				if (maxLen < 2 * j + 1) {
					start = i - j;
					maxLen = 2 * j + 1;
				}
			}
			//偶数扩展
			for (int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
				if (s[i - j] != s[i + j + 1])
					break;
				if (maxLen < 2 * j + 2) {
					start = i - j;
					maxLen = 2 * j + 2;
				}
			}
		}
		return s.substr(start, maxLen);
	}

	//马拉车算法
	string longestPalindrome3(string s) {
		if (s.empty())
			return "";
		//预处理
		string t = "#";
		for (auto c : s) {
			t += c;
			t += "#";
		}
		int n = t.size();
		vector<int> p(n);
		int start = 0;
		int maxLen = 0;
		int id = 0; //能延伸到最右端位置的那个回文子串的中心点位置
		int mx = 0; //回文子串能延伸到的最右端位置
		for (int i = 0; i < n; i++) {
			// mx - i > p[2 * id - i]时，p[i] = p[2 * id - i]
			// mx - i <= p[2 * id - i]时， p[i] >= mx - i
			// 即mx > i 时，p[i] >= min(p[2 * id - i, mx - i])
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]])
				p[i]++;
			if (mx < i + p[i]) {
				mx = i + p[i];
				id = i;
			}
			if (maxLen < p[i] - 1) {
				maxLen = p[i] - 1;
				start = (i - p[i] + 1) / 2;
			}
		}
		return s.substr(start, maxLen);
	}
};

int main()
{
	Solution solution;
	string s1 = "babad";
	cout << s1 << "的最长回文子串:" << endl;
	cout << solution.longestPalindrome1(s1) << endl;
	cout << solution.longestPalindrome2(s1) << endl;
	cout << solution.longestPalindrome3(s1) << endl;
	string s2 = "cbbd";
	cout << s2 << "的最长回文子串:" << endl;
	cout << solution.longestPalindrome1(s2) << endl;
	cout << solution.longestPalindrome2(s2) << endl;
	cout << solution.longestPalindrome3(s2) << endl;
	return 0;
}
