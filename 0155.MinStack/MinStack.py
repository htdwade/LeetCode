'''

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

'''

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.dataStack = []
        self.minStack = []

    def push(self, x: int) -> None:
        self.dataStack.append(x)
        if len(self.minStack) == 0 or x <= self.minStack[-1]:
            self.minStack.append(x)

    def pop(self) -> None:
        if len(self.dataStack) == 0:
            raise Exception("stack is empty")
        if self.dataStack[-1] == self.minStack[-1]:
            self.minStack.pop()
        self.dataStack.pop()

    def top(self) -> int:
        return self.dataStack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()