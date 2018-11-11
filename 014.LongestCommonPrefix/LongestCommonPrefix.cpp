/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(auto str : strs){
            for(int i = 0; i < prefix.size(); i++){
                if(i == str.size() || str[i] != prefix[i]){
                    prefix = prefix.substr(0, i);
                    break;
                }
            }
        }
        return prefix;
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> nums = {{"flower", "f", "f"},
                                   {"dog", "racecar", "car"}};
    for(auto strs : nums){
        for(auto str : strs)
            cout << "Input: " << str << "\t";
        cout << endl;
        cout << "Output: " << solution.longestCommonPrefix(strs) << endl;
        cout << endl;
    }
    return 0;
}
