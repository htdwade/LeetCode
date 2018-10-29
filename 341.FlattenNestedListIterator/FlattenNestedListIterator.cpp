/*

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers 
or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
			 the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
			 the order of elements returned by next should be: [1,4,6].

*/


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//dfs
class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		dfs(nestedList);
	}

	int next() {
		return res[count++];
	}

	bool hasNext() {
		return count < res.size();
	}
private:
	vector<int> res;
	int count = 0;
	void dfs(vector<NestedInteger> &nestedList) {
		for (auto t : nestedList) {
			if (t.isInteger())
				res.push_back(t.getInteger());
			else
				dfs(t.getList());
		}
	}
};

//stack
class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; i--)
			s.push(nestedList[i]);
	}

	int next() {
		int t = s.top().getInteger();
		s.pop();
		return t;
	}

	bool hasNext() {
		while (!s.empty()) {
			NestedInteger cur = s.top();
			if (cur.isInteger())
				return true;
			s.pop();
			vector<NestedInteger> temp = cur.getList();
			for (int i = temp.size() - 1; i >= 0; i--)
				s.push(temp[i]);
		}
		return false;
	}

private:
	stack<NestedInteger> s;
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{	
	return 0;
}