/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty() || matrix[0].empty())
			return res;
		int rowBegin = 0;
		int rowEnd = matrix.size() - 1;
		int colBegin = 0;
		int colEnd = matrix[0].size() - 1;
		while (rowBegin <= rowEnd && colBegin <= colEnd) {
			//向右打印一行
			for (int i = colBegin; i <= colEnd; i++)
				res.push_back(matrix[rowBegin][i]);
			rowBegin++;
			//向下打印一列
			for (int i = rowBegin; i <= rowEnd; i++)
				res.push_back(matrix[i][colEnd]);
			colEnd--;
			//向左打印一行
			if (rowBegin <= rowEnd) {
				for (int i = colEnd; i >= colBegin; i--)
					res.push_back(matrix[rowEnd][i]);
			}
			rowEnd--;
			//向上打印一列
			if (colBegin <= colEnd) {
				for (int i = rowEnd; i >= rowBegin; i--)
					res.push_back(matrix[i][colBegin]);
			}
			colBegin++;
		}
		return res;
	}
};

int main()
{
	Solution solution;
	vector<vector<int>> matrix1 = { {1, 2, 3},
									{4, 5, 6},
									{7, 8, 9} };
	vector<vector<int>> matrix2 = { {1, 2, 3, 4},
									{5, 6, 7, 8},
									{9, 10, 11, 12} };
	vector<int> res1 = solution.spiralOrder(matrix1);
	for (auto a : res1)
		cout << a << '\t';
	cout << '\n';
	vector<int> res2 = solution.spiralOrder(matrix2);
	for (auto a : res2)
		cout << a << '\t';
	return 0;
}