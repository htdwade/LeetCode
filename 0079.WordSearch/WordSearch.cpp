/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not be 
used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		if (word.empty())
			return true;
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (dfs(board, word, visited, i, j, 0))
					return true;
		return false;
	}

private:
	bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index) {
		if (index == word.size())
			return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
			return false;
		visited[i][j] = true;
		bool find = dfs(board, word, visited, i - 1, j, index + 1)
			|| dfs(board, word, visited, i, j + 1, index + 1)
			|| dfs(board, word, visited, i + 1, j, index + 1)
			|| dfs(board, word, visited, i, j - 1, index + 1);
		visited[i][j] = false;
		return find;
	}
};

int main()
{
	Solution solution;
	vector<vector<char>> board = { {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
	string word1 = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";
	cout << solution.exist(board, word1) << endl;
	cout << solution.exist(board, word2) << endl;
	cout << solution.exist(board, word3) << endl;
	return 0;
}