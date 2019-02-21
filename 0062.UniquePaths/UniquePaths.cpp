/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right 
corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//DP
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (i == 1 || j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		return dp[m][n];
	}

	//组合数
	int uniquePaths2(int m, int n) {
		long long res = 1;
		for (int i = m; i <= m + n - 2; i++)
			res = res * i / (i - m + 1);
		return res;
	}
};

int main()
{
	Solution solution;
	cout << solution.uniquePaths(3, 2) << endl;
	cout << solution.uniquePaths(7, 3) << endl;
	cout << solution.uniquePaths2(3, 2) << endl;
	cout << solution.uniquePaths2(7, 3) << endl;
 	return 0;
}
