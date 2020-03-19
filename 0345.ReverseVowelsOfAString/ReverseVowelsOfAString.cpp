/*

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。

*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() == 0)
            return s;
        string vowels = "aeiouAEIOU";
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && vowels.find(s[i]) == string::npos)
                i++;
            while(i < j && vowels.find(s[j]) == string::npos)
                j--;
            if(i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

