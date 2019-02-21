/*

There are 1000 buckets, one and only one of them contains poison, the rest are filled 
with water. They all look the same. If a pig drinks that poison it will die within 15 minutes.
What is the minimum amount of pigs you need to figure out which bucket contains the poison 
within one hour.

Answer this question, and write an algorithm for the follow-up general case.

Follow-up:

If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) 
you need to figure out the "poison" bucket within p minutes? There is exact one bucket with 
poison.

*/


#include <iostream>

using namespace std;

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int pig = 0;
		while (pow(minutesToTest / minutesToDie + 1, pig) < buckets)
			pig++;
		return pig;
	}
};

int main()
{	
	Solution solution;
	cout << solution.poorPigs(1000, 15, 60) << endl;
	return 0;
}