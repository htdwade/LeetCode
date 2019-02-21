/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		dataStack.push(x);
		if (minStack.empty() || x < minStack.top())
			minStack.push(x);
		else
			minStack.push(minStack.top());
	}

	void pop() {
		dataStack.pop();
		minStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minStack.top();
	}

private:
	stack<int> dataStack;
	stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.top() << endl;
	cout << minStack.getMin() << endl;
	return 0;
}