/*

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3

Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		int digits = 1;
		while (true) {
			long long total = 9 * pow(10, digits - 1);
			if (n - total * digits <= 0)
				break;
			n -= total * digits;
			digits++;
		}
		int number = pow(10, digits - 1) + (n - 1) / digits;
		int index = (n - 1) % digits;
		return to_string(number)[index] - '0';
	}
};

int main()
{
	Solution solution;
	cout << solution.findNthDigit(3) << endl;
	cout << solution.findNthDigit(11) << endl;
	return 0;
}
