/*

Given a string containing only digits, restore it by returning all possible 
valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string t;
		dfs(res, t, s, 0, 0);
		return res;
	}

private:
	void dfs(vector<string>& res, string t, string& s, int count, int index) {
		if (count > 4)
			return;
		if (index == s.size() && count == 4) {
			res.push_back(t);
			return;
		}
		for (int i = 1; i <= 3; i++) {
			if (index + i > s.size())
				break;
			string temp = s.substr(index, i);
			if ((temp.find_first_of('0') == 0 && temp.size() > 1) || temp.size() == 3 && stoi(temp) > 255)
				continue;
			dfs(res, t + temp + ((count == 3) ? "" : "."), s, count + 1, index + i);
		}
	}
};

int main()
{
	Solution solution;
	vector<string> res = solution.restoreIpAddresses("25525511135");
	for (auto s : res)
		cout << s << endl;
	return 0;
}