/*
8. String to Integer (atoi)

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. If the numerical value is out of the range of representable values, INT_MAX (231 ? 1) or INT_MIN (?231) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
Thefore INT_MIN (?231) is returned.
*/

#include <climits>

#include "../include/include.h"

// class Solution_findNumInStr {
// public:
// 	int sign;
// 	int st, ed;

// 	void resetAll() {
// 		st = -1;
// 		ed = -1;
// 		sign = 1;
// 	}

// 	int mySubAtoi(const string s) {
// 		long long sum = 0;
// 		int len = s.length();
// 		for (auto i = 0; i<s.length(); i++) {
// 			sum *= 10;
// 			if (sign == 1)
// 				sum += s[i] - '0';
// 			else
// 				sum -= s[i] - '0';
// 			if (sign == 1 && sum > INT_MAX)
// 				return INT_MAX;
// 			if (sign == -1 && sum < INT_MIN)
// 				return INT_MIN;
// 		}
// 		return sum;
// 	}
// 	int myAtoi(string str) {
// 		resetAll();
// 		for (auto i = 0; i<str.length(); i++) {
// 			if (str[i] == '+') {
// 				if (st != -1)
// 					resetAll();
// 				else {
// 					sign = 1;
// 					st = i + 1;
// 				}
// 			}
// 			else if (str[i] == '-') {
// 				if (st != -1)
// 					resetAll();
// 				else {
// 					sign = -1;
// 					st = i + 1;
// 				}
// 			}
// 			else if (str[i] >= '0' && str[i] <= '9') {
// 				if (st == -1) {
// 					st = i;
// 				}
// 				ed = i + 1;
// 			}
// 			else if (str[i] == ' ') {
// 				if (st != -1) {
// 					break;
// 				}
// 			}
// 			else {
// 				if (st != -1)
// 					resetAll();
// 			}
// 		}
// 		if (ed == -1)
// 			return 0;
// 		string num = str.substr(st, ed - st);
// 		return mySubAtoi(num);
// 	}
// };

class Solution {
public:
	int sign;
	int st, ed;

	void resetAll() {
		st = -1;
		ed = -1;
		sign = 1;
	}

	int mySubAtoi(const string s) {
		long long sum = 0;
		for (auto i = 0; i<s.length(); i++) {
			sum *= 10;
			if (sign == 1)
				sum += s[i] - '0';
			else
				sum -= s[i] - '0';
			if (sign == 1 && sum > INT_MAX)
				return INT_MAX;
			if (sign == -1 && sum < INT_MIN)
				return INT_MIN;
		}
		return sum;
	}
	int myAtoi(string str) {
		resetAll();
		for (auto i = 0; i<str.length(); i++) {
			if (str[i] == '+') {
				if (st == -1 && ed == -1) {
					sign = 1;
					st = i + 1;
				}
				else if (st != -1 && ed == -1)
					return 0;
				else
					break;
			}
			else if (str[i] == '-') {
				if (st == -1 && ed == -1) {
					sign = -1;
					st = i + 1;
				}
				else if (st != -1 && ed == -1)
					return 0;
				else
					break;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				if (st == -1)
					st = i;
				ed = i + 1;
			}
			else if (str[i] == ' ') {
				if (st == -1 && ed == -1)
					continue;
				if (st != -1 && ed == -1)
					return 0;
				break;
			}
			else {
				if (ed == -1)
					return 0;
				break;
			}
		}
		if (ed == -1)
			return 0;
		string num = str.substr(st, ed - st);
		return mySubAtoi(num);
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
				case '\"': result.push_back('\"'); break;
				case '/': result.push_back('/'); break;
				case '\\': result.push_back('\\'); break;
				case 'b': result.push_back('\b'); break;
				case 'f': result.push_back('\f'); break;
				case 'r': result.push_back('\r'); break;
				case 'n': result.push_back('\n'); break;
				case 't': result.push_back('\t'); break;
				default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}