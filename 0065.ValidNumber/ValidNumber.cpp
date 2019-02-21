/*

Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up 
front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

*/

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//正则表达式
	bool isNumber(string s) {
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		if (s.empty())
			return false;
		regex pattern("[+-]?((\\d+(\\.\\d*)?)|(\\.\\d+))([Ee][+-]?\\d+)?");
		return regex_match(s, pattern);
	}

	// DFA
	bool isNumber2(string s) {
		vector<unordered_map<string, int>> state = { {},
													{{"blank", 1}, {"sign", 2}, {"digit", 3}, {".", 4}},
													{{"digit", 3}, {".", 4}},
													{{"blank", 9}, {"digit", 3}, {"exp", 6}, {".", 5}},
													{{"digit", 5}},
													{{"digit", 5}, {"exp", 6}, {"blank", 9}},
													{{"sign", 7}, {"digit", 8}},
													{{"digit", 8}},
													{{"digit", 8}, {"blank", 9}},
													{{"blank", 9}}
		};
		int curState = 1;
		for (auto c : s) {
			string t = "";
			if (c == ' ')
				t = "blank";
			if (c == '+' || c == '-')
				t = "sign";
			if (c >= '0' && c <= '9')
				t = "digit";
			if (c == '.')
				t = ".";
			if (c == 'e' || c == 'E')
				t = "exp";
			if (state[curState].find(t) == state[curState].end())
				return false;
			curState = state[curState][t];
		}
		if (curState == 3 || curState == 5 || curState == 8 || curState == 9)
			return true;
		return false;
	}

};

int main()
{
	Solution solution;
	cout << "正则:" << solution.isNumber("0") << endl;
	cout << "DFA:" << solution.isNumber2("0") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber(" 0.1 ") << endl;
	cout << "DFA:" << solution.isNumber2(" 0.1 ") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("abc") << endl;
	cout << "DFA:" << solution.isNumber2("abc") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("1 a") << endl;
	cout << "DFA:" << solution.isNumber2("1 a") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("2e10") << endl;
	cout << "DFA:" << solution.isNumber2("2e10") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber(" -90e3   ") << endl;
	cout << "DFA:" << solution.isNumber2(" -90e3   ") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber(" 1e") << endl;
	cout << "DFA:" << solution.isNumber2(" 1e") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber("e3") << endl;
	cout << "DFA:" << solution.isNumber2("e3") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber(" 6e-1") << endl;
	cout << "DFA:" << solution.isNumber2(" 6e-1") << endl;
	cout << '\n';
	cout << "正则:" << solution.isNumber(" 99e2.5 ") << endl;
	cout << "DFA:" << solution.isNumber2(" 99e2.5 ") << endl;
	cout << '\n';
	return 0;
}