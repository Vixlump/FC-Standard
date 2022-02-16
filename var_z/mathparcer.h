#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void toExpr(string expr)
{
	const string opers = "*/+-";
	const auto isnum = [](char ch) {return isdigit(ch) || (ch == '.'); };

	vector<string> tokens;
	bool gotoper = true;

	expr.erase(remove_if(expr.begin(), expr.end(), [](char ch){return isspace(ch);}), expr.end());

	for (const auto *p = expr.c_str(); *p;)
		if (gotoper && ((isnum(*p) || (((*p == '-') || (*p == '+')) && isnum(*(p + 1)))))) {
			const char* const b = ((*p == '-') || (*p == '+')) ? p++ : p;

			for (; isnum(*p); ++p);
			gotoper = false;
			const auto s = string(b, p);

			if (count(s.begin(), s.end(), '.') < 2)
				tokens.push_back(s);
			else {
				cout << "Invalid number\n";
				return;
			}
		} else
			if (!gotoper) {
				gotoper = true;
				if (opers.find(*p) != string::npos)
					tokens.push_back(string(1, *p++));
				else {
					cout << "Invalid operator\n";
					return;
				}
			} else {
				cout << "Invalid expression\n";
				return;
			}

	if (gotoper) {
		cout << "Missing final number\n";
		return;
	}

	while (tokens.size() > 1) {
		auto op = find_if(tokens.begin(), tokens.end(), [](const string& st){return st == "*" || st == "/";});

		if (op == tokens.end())
			op = tokens.begin() + 1;

		const double op1 = stod(*(op - 1));
		const double op2 = stod(*(op + 1));
		double res = 0.0;

		switch ((*op)[0]) {
			case '*':
				res = op1 * op2;
				break;

			case '/':
				res = op1 / op2;
				break;

			case '+':
				res = op1 + op2;
				break;

			case '-':
				res = op1 - op2;
				break;

			default:
				cout << "Fatal error\n";
				return;
		}

		*(op - 1) = to_string(res);
		tokens.erase(op, op + 2);
	}

	cout << stod(tokens.front()) << endl;
}

int main()
{
	cout << "Enter expression :";
	string expr;

	getline(std::cin, expr);

	toExpr(expr);
}