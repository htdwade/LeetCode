/*

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

package leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static int lengtnhOfLongestSubstring(String s) {
        int maxlen = 0;
        int start = 0;
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i< s.length(); i++) {
            if(map.containsKey(s.charAt(i)))
            	start = Math.max(map.get(s.charAt(i)) + 1, start);
            maxlen = Math.max(i - start + 1, maxlen);
            map.put(s.charAt(i), i);
        }
        return maxlen;
    }

    public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		int maxlen = lengtnhOfLongestSubstring(s);
		System.out.println(maxlen);
	}
}
