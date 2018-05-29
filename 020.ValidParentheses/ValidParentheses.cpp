/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '['){
                sta.push(c);
                continue;
               }
            if(sta.empty())
                return false;
            if(c == ')' && sta.top() != '(')
                return false;
            if(c == '}' && sta.top() != '{')
                return false;
            if(c == ']' && sta.top() != '[')
                return false;
            sta.pop();
        }
        return sta.empty();
    }
};

int main()
{
    Solution solution;
    vector<string> nums = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    for(auto s : nums){
        cout << "Input: " << s << endl;
        cout << "Output: " << solution.isValid(s) << endl;
        cout << endl;
    }
    return 0;
}
