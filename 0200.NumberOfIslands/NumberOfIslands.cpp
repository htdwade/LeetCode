/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island
is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int count = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (grid[i][j] == '1') {
					count++;
					dfs(grid, i, j);
				}
		return count;
	}

private:
	void dfs(vector<vector<char>>& grid, int x, int y) {
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1') {
			grid[x][y] = '0';
			dfs(grid, x, y - 1);
			dfs(grid, x - 1, y);
			dfs(grid, x, y + 1);
			dfs(grid, x + 1, y);
		}
	}
};

int main()
{
	Solution solution;
	vector<vector<char>> grid1 = { {'1', '1', '1', '1', '0'}, 
								  {'1', '1', '0', '1', '0'}, 
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '0', '0', '0'} };
	cout << solution.numIslands(grid1) << endl;
	vector<vector<char>> grid2 = { {'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'} };
	cout << solution.numIslands(grid2) << endl;
	return 0;
}