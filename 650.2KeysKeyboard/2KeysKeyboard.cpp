/*

Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. 
Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
The n will be in the range [1, 1000].

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//DP
	int minSteps(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[1] = 0;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j < i; j++)
				if (i % j == 0) {
					dp[i] = min(dp[i], dp[j] + i / j);
				}
		return dp[n];
	}

	//Greedy
	int minSteps2(int n) {
		int res = 0;
		for (int i = 2; i <= n; i++) {
			while (n % i == 0) {
				res += i;
				n /= i;
			}
		}
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.minSteps(3) << endl;
	cout << solution.minSteps2(3) << endl;
 	return 0;
}
