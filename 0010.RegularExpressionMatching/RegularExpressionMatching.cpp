/*

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //递归
    bool isMatch(string s, string p) {
       if(p.empty())
            return s.empty();
        if(p.size() == 1)
            return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
        if(p[1] == '*')
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }

    //动态规划
    bool isMatch2(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            dp[0][i] = i > 1 && p[i - 1] == '*' && dp[0][i - 2];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    vector<string> vs = {"aa", "aa", "ab", "aab", "mississippi"};
    vector<string> vp = {"a", "a*", ".*", "c*a*b", "mis*is*ip*."};
    for(int i = 0; i < 5; i++){
        cout << "Input: " << endl;
        cout << "s = " << vs[i] << endl;
        cout << "p = " << vp[i] << endl;
        cout << "Output: " << solution.isMatch(vs[i], vp[i]) << endl;
        cout << "Output: " << solution.isMatch2(vs[i], vp[i]) << endl;
    }
    return 0;
}
