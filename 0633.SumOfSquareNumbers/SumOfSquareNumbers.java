/*

给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
 

示例2:

输入: 3
输出: False

*/

class Solution {
    public boolean judgeSquareSum(int c) {
        if (c < 0) 
			return false;
		int left = 0, right = (int)Math.sqrt(c);
		while (left <= right) {
			int sum = left * left + right * right;
			if (sum == c)
				return true;
			else if (sum < c)
				left++;
			else
				right--;
		}
		return false;
    }
}