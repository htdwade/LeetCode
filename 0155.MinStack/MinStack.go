/*

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

*/

package problem0155

import "C"

type MinStack struct {
	dataStack []int
	minStack  []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(x int) {
	this.dataStack = append(this.dataStack, x)
	if len(this.minStack) == 0 || x <= this.minStack[len(this.minStack)-1] {
		this.minStack = append(this.minStack, x)
	}
}

func (this *MinStack) Pop() {
	if len(this.dataStack) == 0 {
		panic("stack is empty")
	}
	if this.dataStack[len(this.dataStack)-1] == this.minStack[len(this.minStack)-1] {
		this.minStack = this.minStack[:len(this.minStack)-1]
	}
	this.dataStack = this.dataStack[:len(this.dataStack)-1]
}

func (this *MinStack) Top() int {
	return this.dataStack[len(this.dataStack)-1]
}

func (this *MinStack) GetMin() int {
	return this.minStack[len(this.minStack)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
