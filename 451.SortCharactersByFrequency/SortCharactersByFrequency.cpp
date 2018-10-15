/*

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.

Note that 'A' and 'a' are treated as two different characters.s

*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> m;
		for (auto c : s)
			m[c]++;
		vector<string> bucket(s.size() + 1);
		for (auto kv : m) {
			int n = kv.second;
			bucket[kv.second].append(n, kv.first);
		}
		string r;
		for (int i = bucket.size() - 1; i >= 0; i--) {
			for (int j = 0; j < bucket[i].size(); j++)
				r.push_back(bucket[i][j]);
		}
		return r;
	}
};

int main()
{
	Solution solution;
	string s1 = "tree";
	cout << solution.frequencySort(s1) << endl;
	string s2 = "cccaaa";
	cout << solution.frequencySort(s2) << endl;
	string s3 = "Aabb";
	cout << solution.frequencySort(s3) << endl;
	return 0;
}
