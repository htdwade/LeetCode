/*

Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/


#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
	//bfs
	int numSquares(int n) {
		if (n <= 0)
			return 0;
		//把0...n中的完全平方数和看做一个个结点，如果一个结点加上一个完全平方数能到达另一个结点，则
		//可以连接这两点，则所求问题即为0点到n点的最短可达路径.
		//dist[i]表示i点到0点的最短路径
		vector<int> dist(n + 1, INT_MAX);
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		while (q.size()) {
			int t = q.front();
			if (t == n)
				return dist[n];
			for (int i = 1; i * i + t <= n; i++) {
				int j = i * i + t;
				if (dist[j] > dist[t] + 1) {
					dist[j] = dist[t] + 1;
					q.push(j);
				}
			}
			q.pop();
		}
		return 0;
	}

	//dp
	int numSquares2(int n) {
		if (n <= 0)
			return 0;
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j * j <= i; j++)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		return dp[n];
	}

};

int main()
{
	Solution solution;
	cout << solution.numSquares(12) << endl;
	cout << solution.numSquares(13) << endl;
	return 0;
}