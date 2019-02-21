/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        vector<int> hash(256, -1);
        for(int i= 0; i < s.size(); i++){
            if(hash[s[i]] >= start)
                start = hash[s[i]] + 1;
            hash[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    string s1 = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s1) << endl;
    string s2 = "bbbbb";
    cout << solution.lengthOfLongestSubstring(s2) << endl;
    string s3 = "pwwkew";
    cout << solution.lengthOfLongestSubstring(s3) << endl;
    return 0;
}
