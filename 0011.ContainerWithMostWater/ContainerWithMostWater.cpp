/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the
two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains
the most water.

Note: You may not slant the container and n is at least 2.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            int temp = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, temp);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};

int main()
{
    Solution solution;
    vector<int> height = {7, 5, 6, 9};
    cout << solution.maxArea(height) << endl;
    return 0;
}
