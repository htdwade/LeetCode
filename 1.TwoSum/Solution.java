/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

package leetcode;

import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static int[] twoSum(int[] nums, int target) {
        int[] re = new int[2];
	    Map<Integer, Integer> map = new HashMap<Integer,Integer>();
	    for(int i = 0; i < nums.length; i++){
	    	int numToFind = target - nums[i];
	    	if(map.containsKey(numToFind)){
	    		re[0] = map.get(numToFind);
	    		re[1] = i;
	    		break;
	    	}
	    	map.put(nums[i], i);
	    }
	    return re;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int numbers[] = {2,7,11,15};
		int target = 9;
		int[] re = new int[2];
		re = twoSum(numbers,target);
		System.out.println(re[0]+"\t"+re[1]);
	}

}
