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
#include <cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome1(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(i - j < 2)
                    dp[j][i] = (s[i] == s[j]);
                else
                    dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
                if(dp[j][i] && maxLen < (i - j + 1)){
                    maxLen = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string longestPalindrome2(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            //回文长度为奇数
            for(int j = 0; (i - j >= 0) && (i + j < n); j++){
                if(s[i - j] != s[i + j])
                    break;
                if(maxLen < 2 * j + 1){
                    maxLen = 2 * j + 1;
                    start = i - j;
                }
            }

            //回文长度为偶数
            for(int j = 0; (i - j >= 0) && (i + j + 1 < n); j++){
                if(s[i - j] != s[i + j + 1])
                    break;
                if(maxLen < 2 * j + 2){
                    maxLen = 2 * j + 2;
                    start = i - j;
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string longestPalindrome3(string s) {
        //预处理
        string t = "#";
        for(int i = 0; i < s.size(); i++){
            t += s[i];
            t += "#";
        }
        int id = 0; //最大回文子串中心的位置
        int mx = 0; //最大回文子串的边界
        int n = t.size();
        int p[n];
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i< n; i++){
            //mx > i 时，p[i] >= min(p[2 * id - i], mx - i)
            p[i] =  mx > i ? min(p[2 * id - i], mx - i) : 1;
            while(i - p[i] >= 0 && i + p[i] < n && t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if(mx < i + p[i] - 1){
                mx = i + p[i] - 1;
                id = i;
            }
            if(maxLen < p[i] - 1){
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
