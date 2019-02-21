/*

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

*/


#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		int i = 0, j = s.size() - 1;
		while (i < j) {
			while (i < j && vowels.find(s[i]) == vowels.end())
				i++;
			while (i < j && vowels.find(s[j]) == vowels.end())
				j--;
			if (i < j)
				swap(s[i++], s[j--]);
		}
		return s;
	}
};

int main()
{
	Solution solution;
	cout << solution.reverseVowels("hello") << endl;
	cout << solution.reverseVowels("leetcode") << endl;
	return 0;
}