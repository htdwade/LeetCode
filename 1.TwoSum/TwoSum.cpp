/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> re;
        for(int i = 0;i < nums.size();i++){
            int numToFind = target-nums[i];
            if(hash.find(numToFind)!=hash.end()){
                re.push_back(hash[numToFind]);
                re.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return re;
    }
};

int main()
{
    Solution solution;
    int a[4] = {2,7,11,15};
    vector<int> nums(a,a+4);
    vector<int>::iterator iter;
    int target = 9;
    vector<int> re = solution.twoSum(nums,target);
    for(iter = re.begin();iter != re.end();iter++)
        cout<<*iter<<"\t";
    return 0;
}
