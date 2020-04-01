/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        if(len & 0x1 == 1)
            return findKthNum(nums1, 0, m, nums2, 0, n, len/2 + 1);
        else
            return (findKthNum(nums1, 0, m, nums2, 0, n, len/2) + findKthNum(nums1, 0, m, nums2, 0, n, len/2 + 1)) / 2.0;
    }

    int findKthNum(vector<int>& nums1, int beg1, int m, vector<int>& nums2, int beg2, int n, int k){
        if(m > n)
            return findKthNum(nums2, beg2, n, nums1, beg1, m, k);
        if(m == 0)
            return nums2[beg2 + k - 1];
        if(k == 1)
            return min(nums1[beg1], nums2[beg2]);
        int i = min(m, k/2);
        int j = k - i;
        if(nums1[beg1 + i - 1] > nums2[beg2 + j - 1])
            return findKthNum(nums1, beg1, i, nums2, beg2 + j, n - j, k - j);
        else
            return findKthNum(nums1, beg1 + i, m - i, nums2, beg2, j, k - i);
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << solution.findMedianSortedArrays(nums3, nums4) << endl;
    return 0;
}
