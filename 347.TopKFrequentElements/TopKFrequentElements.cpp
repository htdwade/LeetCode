/*

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	//最小堆，使用优先级队列
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto a : nums)
			m[a]++;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (auto kv : m) {
			pq.push({ kv.second, kv.first });
			while (pq.size() > k)
				pq.pop();
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}

	//快速选择
	vector<int> topKFrequent2(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto a : nums)
			m[a]++;
		vector<pair<int, int>> tmp;
		for (auto kv : m)
			tmp.push_back({ kv.first, kv.second });
		vector<int> res;
		int kthLargest = findKthLargest(tmp, k);
		for (auto t : tmp) {
			if (t.second >= kthLargest && res.size() < k)
				res.push_back(t.first);
		}
		return res;
	}

	int findKthLargest(vector<pair<int,int>>& tmp, int k) {
		int target = tmp.size() - k + 1;
		int left = 0, right = tmp.size() - 1;
		int index;
		while (left <= right) {
			index = partition(tmp, left, right);
			if (index == target - 1)
				break;
			else if (index < target - 1)
				left = index + 1;
			else
				right = index - 1;
		}
		return tmp[index].second;
	}

	int partition(vector<pair<int, int>>& tmp, int left, int right) {
		int x = tmp[right].second;
		int i = left - 1;
		int j = left;
		while (j < right) {
			if (tmp[j].second <= x)
				swap(tmp[++i], tmp[j]);
			j++;
		}
		swap(tmp[i + 1], tmp[right]);
		return i + 1;
	}

	//桶排序
	vector<int> topKFrequent3(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto a : nums)
			m[a]++;
		vector<vector<int>> bucket(nums.size() + 1);
		for (auto kv : m)
			bucket[kv.second].push_back(kv.first);
		vector<int> res;
		for (int i = bucket.size() - 1; i >= 0; i--) {
			for (int j = 0; j < bucket[i].size(); j++) {
				res.push_back(bucket[i][j]);
				if (res.size() == k)
					return res;
			}
		}
	}

};

int main()
{
	Solution solution;
	vector<int> nums1 = { 1,1,1,2,2,3 };
	int k1 = 2;
	vector<int> nums2 = { 1 };
	int k2 = 1;
	vector<int> res1 = solution.topKFrequent3(nums1, k1);
	for (auto a : res1)
		cout << a << '\t';
	vector<int> res2 = solution.topKFrequent3(nums2, k2);
	for (auto b : res2)
		cout << b << '\t';
	return 0;
}
