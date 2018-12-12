/*

Given an array A of non-negative integers, return an array consisting of all the even elements of A, 
followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int i = 0, j = A.size() - 1;
		while (i < j) {
			while (i < j && (A[i] % 2 == 0))
				i++;
			while (i < j && (A[j] % 2 == 1))
				j--;
			swap(A[i++], A[j--]);
		}
		return A;
	}
};

int main()
{
	Solution solution;
	vector<int> A = { 3, 1, 2, 4 };
	vector<int> res = solution.sortArrayByParity(A);
	for (auto a : res)
		cout << a << '\t';
	return 0;
}