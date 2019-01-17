/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<bool> cols(n, false);
		vector<bool> diags1(2 * n - 1, false);
		vector<bool> diags2(2 * n - 1, false);
		int count = 0;
		dfs(0, count, n, cols, diags1, diags2);
		return count;
	}

private:
	void dfs(int row, int& count, int n, vector<bool>& cols, vector<bool>& diags1, vector<bool>& diags2) {
		if (row == n) {
			count++;
			return;
		}
		for (int col = 0; col < n; col++) {
			if (cols[col] || diags1[row - col + n - 1] || diags2[row + col])
				continue;
			cols[col] = true, diags1[row - col + n - 1] = true, diags2[row + col] = true;
			dfs(row + 1, count, n, cols, diags1, diags2);
			cols[col] = false, diags1[row - col + n - 1] = false, diags2[row + col] = false;
		}
	}
};

int main()
{
	Solution solution;
	cout << solution.totalNQueens(4) << endl;
	cout << solution.totalNQueens(8) << endl;
	return 0;
}