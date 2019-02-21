/*

Given a collection of intervals, find the minimum number of intervals you need to remove to make 
the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), [](const Interval& t1, const Interval& t2) {return t1.end < t2.end; });
		int count = 1;
		int end = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start >= end) {
				count++;
				end = intervals[i].end;
			}
		}
		return intervals.size() - count;
	}
};

int main()
{
	Solution solution;
	Interval p1(1, 2);
	Interval p2(2, 3);
	Interval p3(3, 4);
	Interval p4(1, 3);
	vector<Interval> intervals1 = { p1, p2, p3, p4 };
	cout << solution.eraseOverlapIntervals(intervals1) << endl;
	vector<Interval> intervals2 = { p1, p1, p1 };
	cout << solution.eraseOverlapIntervals(intervals2) << endl;
	vector<Interval> intervals3 = { p1, p2 };
	cout << solution.eraseOverlapIntervals(intervals3) << endl;
	return 0;
}
