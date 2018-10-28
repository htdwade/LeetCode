/*

Given a string S, we can transform every letter individually to be lowercase or uppercase 
to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		dfs(S, res, 0);
		return res;
	}

private:
	void dfs(string& S, vector<string>& res, int index) {
		if (index == S.size()) {
			res.push_back(S);
			return;
		}
		dfs(S, res, index + 1);
		if (isalpha(S[index])) {
			S[index] ^= 32;
			dfs(S, res, index + 1);
		}
	}

};

int main()
{
	Solution solution;
	vector<string> res = solution.letterCasePermutation("a1b2");
	for (auto s : res)
		cout << s << '\t';
	return 0;
}