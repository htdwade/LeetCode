/*

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.

*/


#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);
		int left = max(A, E);
		int right = min(C, G);
		int top = min(D, H);
		int bottom = max(B, F);
		int temp = 0;
		if (right > left && top > bottom)
			temp = (right - left) * (top - bottom);
		return area1 + area2 - temp;
	}
};

int main()
{
	Solution solution;
	cout << solution.computeArea(-3, 0, 3, 4, 0, -1, 9 ,2) << endl;
 	return 0;
}
