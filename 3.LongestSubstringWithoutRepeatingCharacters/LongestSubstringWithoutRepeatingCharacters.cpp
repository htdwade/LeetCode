/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int start = 0;
        vector<int> hash(256,-1);
        for (int i = 0; i < s.length(); i++) {
            if(hash[s[i]] >= start)
                start = hash[s[i]] + 1;
            maxlen = max(i - start + 1, maxlen);
            hash[s[i]] = i;
        }
        return maxlen;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution solution;
    int re = solution.lengthOfLongestSubstring(s);
    cout<<re<<endl;
    return 0;
}
