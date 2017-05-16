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

#include <stdio.h>

#define min(a,b) ((a) < (b)) ? (a) : (b)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    if(len & 0x1 == 1)
        return findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2 + 1);
    else
        return (findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2) + findKthNum(nums1, nums1Size, nums2, nums2Size, len / 2 + 1)) / 2.0;
}

int findKthNum(int* nums1, int m, int* nums2, int n, int k) {
    if(m > n)
        return findKthNum(nums2, n, nums1, m, k);
    if(m == 0)
        return nums2[k - 1];
    if(k == 1)
        return min(nums1[0], nums2[0]);
    int i = min(m, k/2);
    int j = k - i;
    if(nums1[i - 1] > nums2[j - 1])
        return findKthNum(nums1, i, nums2 + j, n - j, k - j);
    else
        return findKthNum(nums1 + i, m - i, nums2, j, k - i);
}

int main(){
    int nums1[] = {4, 5};
    int nums2[] = {1, 2, 3, 6};
    double re = findMedianSortedArrays(nums1, 2, nums2, 4);
    printf("%f\n", re);
    return 0;
}
