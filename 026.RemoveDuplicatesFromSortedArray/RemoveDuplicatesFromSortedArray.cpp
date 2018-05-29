/*

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int index = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        }
        return index;
    }

    int removeDuplicates2(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1])
                count++;
            else
                nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "测试removeDuplicates1: " << solution.removeDuplicates1(nums1) << endl;
    cout << "测试removeDuplicates2: " << solution.removeDuplicates2(nums) << endl;
    return 0;
}
