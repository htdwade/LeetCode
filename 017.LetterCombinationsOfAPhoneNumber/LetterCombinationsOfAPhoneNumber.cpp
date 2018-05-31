/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //迭代
    vector<string> letterCombinations1(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> charmap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> re;
        re.push_back("");
        for(int i = 0; i < digits.size(); i++){
            vector<string> temp;
            string s = charmap[digits[i] - '0'];
            for(int j = 0; j < s.size(); j++)
                for(int k = 0; k < re.size(); k++)
                    temp.push_back(re[k] + s[j]);
            re = temp;
        }
        return re;
    }

    //回溯
    vector<string> letterCombinations2(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> charmap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> re;
        string local;
        generate(charmap, digits, 0, re, local);
        return re;
    }

    void generate(vector<string>& charmap, string& digits, int index, vector<string>& re, string& local){
        if(index == digits.size()){
            re.push_back(local);
            return;
        }
        string s = charmap[digits[index] - '0'];
        for(int i = 0; i < s.size(); i++){
            local.push_back(s[i]);
            generate(charmap, digits, index + 1, re, local);
            local.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    string digits = "23";
    vector<string> re1 = solution.letterCombinations1(digits);
    for(auto s1 : re1)
        cout << s1 << '\t';
    cout << '\n';
    vector<string> re2 = solution.letterCombinations2(digits);
    for(auto s2 : re2)
        cout << s2 << '\t';
    return 0;
}
