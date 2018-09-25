/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) 
                break;
            int target = -nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end){
                if(nums[start] + nums[end] < target)
                    start++;
                else if(nums[start] + nums[end] > target)
                    end--;
                else{
                    result.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start - 1])
                        start++;
                    while(start < end && nums[end] == nums[end + 1])
                        end--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    for(auto re : result)
        cout << '[' << re[0] << ',' << re[1] << ',' << re[2] << ']' << endl;
    return 0;
}
