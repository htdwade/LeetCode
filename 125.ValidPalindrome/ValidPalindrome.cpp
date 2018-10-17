/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while (i < j && !isalnum(s[i]))
				i++;
			while(i < j && !isalnum(s[j]))
				j--;
			if (tolower(s[i++]) != tolower(s[j--]))
				return false;
		}
		return true;
	}
};

int main()
{
	Solution solution;
	cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << solution.isPalindrome("race a car") << endl;
	return 0;
}