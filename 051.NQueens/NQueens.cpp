/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> queen(n, string(n, '.'));
		solveNQueensCore(res, queen, 0, n);
		return res;
	}

private:
	void solveNQueensCore(vector<vector<string>>& res, vector<string>& queen, int row, int n) {
		if (row == n) {
			res.push_back(queen);
			return;
		}
		for (int col = 0; col < n; col++) {
			if (isValid(queen, row, col, n)) {
				queen[row][col] = 'Q';
				solveNQueensCore(res, queen, row + 1, n);
				queen[row][col] = '.';
			}
		}
	}

	bool isValid(vector<string>& queen, int row, int col, int n) {
		//检查同一列是否放置了皇后
		for (int i = 0; i < row; i++)
			if (queen[i][col] == 'Q')
				return false;
		//检查左对角线是否放置了皇后
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (queen[i][j] == 'Q')
				return false;
		//检查右对角线是否放置了皇后
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
			if (queen[i][j] == 'Q')
				return false;
		return true;
	}
};

int main()
{
	Solution solution;
	vector<vector<string>> res = solution.solveNQueens(8);
	for (auto v : res) {
		for (auto s : v)
			cout << s << endl;
		cout << "\n\n";
	}
	return 0;
}