'''

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

'''

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlen = 0
        start = 0
        hash_map = {}
        for i in range(len(s)) :
            if s[i] in hash_map :
                start = max(hash_map[s[i]] + 1, start)
            maxlen = max(i - start + 1, maxlen)
            hash_map[s[i]] = i
        return maxlen

if __name__ == '__main__' :
    s = 'abcabcbb'
    solution = Solution()
    maxlen = solution.lengthOfLongestSubstring(s)
    print(maxlen)
