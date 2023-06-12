/*
 * @lc app=leetcode.cn id=124 lang=golang
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	res := math.MinInt
	oneSideMax(root, &res)
	return res
}

func oneSideMax(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}
	left := max(oneSideMax(root.Left, res), 0)
	right := max(oneSideMax(root.Right, res), 0)
	*res = max(*res, left+right+root.Val)
	return max(left, right) + root.Val
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

// @lc code=end

