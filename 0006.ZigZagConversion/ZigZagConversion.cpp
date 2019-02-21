/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty() || numRows <= 0)
            return "";
        if(numRows == 1)
            return s;
        string res = "";
        vector<string> rows(numRows);
        int row = 0;
        int step = -1;
        for(auto c : s){
            rows[row].push_back(c);
            if(row == 0 || row == numRows - 1)
                step = - step;
            row += step;
        }
        for(auto t : rows)
            res += t;
        return res;
    }

    string convert2(string s, int numRows) {
        if(s.empty() || numRows <= 0)
            return "";
        if(numRows == 1)
            return s;
        string res = "";
        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows - 1){
                for(int j = i; j < s.size(); j += 2 * (numRows - 1))
                    res += s[j];
            }
            else{
                for(int j = i, k = 2 * numRows - 1 - i - 1; j < s.size() || k < s.size(); j += 2 * (numRows - 1), k += 2 * (numRows - 1)){
                    if(j < s.size())
                        res += s[j];
                    if(k < s.size())
                        res += s[k];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 4;
    cout << solution.convert(s, 4) << endl;
    return 0;
}
