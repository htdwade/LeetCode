/*

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets
is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets 
are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits 
are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int i = 0;
		return dfs(s, i);
	}

private:
	string dfs(string& s, int& i) {
		string res = "";
		while (i < s.size() && s[i] != ']') {
			if (isdigit(s[i])) {
				int count = 0;
				while (i < s.size() && isdigit(s[i]))
					count = count * 10 + (s[i++] - '0');
				i++;//'['
				string t = dfs(s, i);
				i++;//']'
				while (count--)
					res += t;
			}
			else
				res += s[i++];
		}
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.decodeString("3[a]2[bc]") << endl;
	cout << solution.decodeString("3[a2[c]]") << endl;
	cout << solution.decodeString("2[abc]3[cd]ef") << endl;
	return 0;
}