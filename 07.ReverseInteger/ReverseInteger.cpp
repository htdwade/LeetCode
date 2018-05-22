/*

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse1(int x) {
       long long re = 0;
       while(x){
        re = re * 10 + x % 10;
        x /= 10;
       }
       return (re > INT_MAX || re < INT_MIN) ? 0 : re;
    }

    int reverse2(int x) {
        int re = 0;
        while(x){
            int temp = re * 10 + x % 10;
            if(temp / 10 != re)
                return 0;
            re = temp;
            x /= 10;
        }
        return re;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {123, -123, 120};
    for(auto x : nums){
        cout << "Input: " << x << endl;
        cout << "reverse1Output: " << solution.reverse1(x) << endl;
        cout << "reverse2Output: " << solution.reverse2(x) << endl;
        cout << endl;
    }
    return 0;
}
