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
	//sort排序
	int findKthLargest1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}

	//优先级队列
	int findKthLargest2(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());
		for (int i = 0; i < k - 1; i++)
			pq.pop();
		return pq.top();
	}

	//快速选择
	int findKthLargest3(vector<int>& nums, int k) {
		int target = nums.size() - k + 1;
		int left = 0, right = nums.size() - 1;
		int index;
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
		while (true) {
			while ( i <= right && nums[i] < pivot) i++;
			while ( j >= left + 1 && nums[j] > pivot) j--;
			if (i >= j)
				break;
			swap(nums[i++], nums[j--]);
		}
		swap(nums[left], nums[j]);
		return j;
	}

	//堆排序
	int findKthLargest4(vector<int>& nums, int k) {
		build_max_heap(nums);
		for (int i = 0; i < k - 1; i++) {
			swap(nums[0], nums[heap_size - 1]);
			heap_size--;
			max_heapify(nums, 0);
		}
		return nums[0];
	}

	int heap_size;
	
	int left(int i) {
		return (i << 1) + 1;
	}

	int right(int i) {
		return (i << 1) + 2;
	}

	void max_heapify(vector<int>& nums, int i) {
		int largest = i;
		int l = left(i), r = right(i);
		if (l < heap_size && nums[l] > nums[largest])
			largest = l;
		if (r < heap_size && nums[r] > nums[largest])
			largest = r;
		if (largest != i) {
			swap(nums[largest], nums[i]);
			max_heapify(nums, largest);
		}
	}

	void build_max_heap(vector<int>& nums) {
		heap_size = nums.size();
		for (int i = (heap_size >> 1) - 1; i >= 0; i--)
			max_heapify(nums, i);
	}

};

int main()
{
	Solution solution;
	vector<int> nums1 = { 3,2,1,5,6,4 };
	int k1 = 2;
	vector<int> nums2 = { 3,2,3,1,2,4,5,5,6 };
	int k2 = 4;
	//cout << solution.findKthLargest1(nums1, k1) << endl;
	//cout << solution.findKthLargest1(nums2, k2) << endl;
	//cout << solution.findKthLargest2(nums1, k1) << endl;
	//cout << solution.findKthLargest2(nums2, k2) << endl;
	//cout << solution.findKthLargest3(nums1, k1) << endl;
	//cout << solution.findKthLargest3(nums2, k2) << endl;
	cout << solution.findKthLargest4(nums1, k1) << endl;
	cout << solution.findKthLargest4(nums2, k2) << endl;
	return 0;
}
