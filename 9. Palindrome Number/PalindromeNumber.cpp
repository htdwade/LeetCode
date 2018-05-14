/*

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome1(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int rev = 0;
        while(x > rev){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev) || (x == rev / 10);
    }

    bool isPalindrome2(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0))
            return false;
        int div = 1;
        while(x / div >= 10)
            div *= 10;
        while(x){
            int l = x / div;
            int r = x % 10;
            if(l != r)
                return false;
            x %= div;
            x /= 10;
            div /= 100;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {121, -121, 10};
    for(auto x : nums){
        cout << "Input: " << x << endl;
        cout << "isPalindrome1Output: " << solution.isPalindrome1(x) << endl;
        cout << "isPalindrome2Output: " << solution.isPalindrome2(x) << endl;
        cout << endl;
    }
    return 0;
}
