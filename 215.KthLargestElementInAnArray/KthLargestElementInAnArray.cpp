/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length

*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	//优先级队列最小堆 O(NlogK) + O(K)
	int findKthLargest1(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (auto a : nums) {
			pq.push(a);
			if (pq.size() > k)
				pq.pop();
		}
		return pq.top();
	}

	//快速选择 O(N) + O(1)
	int findKthLargest2(vector<int>& nums, int k) {
		int target = nums.size() - k + 1;
		int left = 0, right = nums.size() - 1;
		int index = 0;
		while (left <= right) {
			index = partition(nums, left, right);
			if (index == target - 1)
				break;
			else if (index < target - 1)
				left = index + 1;
			else
				right = index - 1;
		}
		return nums[index];
	}

	int partition(vector<int>& nums, int left, int right) {
		int i = left + 1, j = right;
		int pivot = nums[left];
		while (i <= j) {
			while (i <= right && nums[i] <= pivot) i++;
			while (j > left && nums[j] >= pivot) j--;
			if(i < j)
				swap(nums[i++], nums[j--]);
		}
		swap(nums[left], nums[j]);
		return j;
	}
	
};

int main()
{
	Solution solution;
	vector<int> nums1 = { 3,2,1,5,6,4 };
	int k1 = 2;
	vector<int> nums2 = { 3,2,3,1,2,4,5,5,6 };
	int k2 = 4;
	cout << solution.findKthLargest1(nums1, k1) << endl;
	cout << solution.findKthLargest2(nums2, k2) << endl;
	return 0;
}
