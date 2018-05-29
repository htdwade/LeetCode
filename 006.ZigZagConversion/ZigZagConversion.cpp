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
        if( numRows <= 1)
            return s;
        vector<string> strs(numRows);
        int row = 0;
        int step = 0;
        string re;
        for(int i = 0; i < s.size(); i++){
            strs[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            if(row == numRows - 1)
                step = -1;
            row += step;
        }
        for(int i = 0; i < numRows; i++)
            re += strs[i];
        return re;
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
