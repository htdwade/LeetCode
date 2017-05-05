'''

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

'''

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash_map = {}
        for i in range(len(nums)):
            if target - nums[i] in hash_map:
                return [hash_map[target - nums[i]], i]
            else:
                hash_map[nums[i]] = i
        return [-1, -1]
solution = Solution()
print(solution.twoSum([2,7,11,15],9))
