/*

Given two sequences pushed and popped with distinct values, return true 
if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.


Note:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> sta;
		int i = 0;
		for (int x : pushed) {
			sta.push(x);
			while (!sta.empty() && sta.top() == popped[i]) {
				sta.pop();
				++i;
			}
		}
		return sta.empty();
	}
};

int main()
{
	Solution solution;
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,2,1 };
	vector<int> v3 = { 4,3,5,1,2 };
	cout << solution.validateStackSequences(v1, v2) << endl;
	cout << solution.validateStackSequences(v1, v3) << endl;
	return 0;
}