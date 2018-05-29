/*

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int closet = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++){
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target)
                    return sum;
                else if(sum < target)
                    start++;
                else
                    end--;
                if(abs(sum - target) < abs(closet - target))
                    closet = sum;
            }
        }
        return closet;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << solution.threeSumClosest(nums, target) << endl;
    return 0;
}
