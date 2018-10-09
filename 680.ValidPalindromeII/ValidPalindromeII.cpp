/*

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j])
				return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
			i++;
			j--;
		}
		return true;
	}

	bool isPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}

};

int main()
{
	Solution solution;
	cout << solution.validPalindrome("aba") << endl;
	cout << solution.validPalindrome("abca") << endl;
	return 0;
}
