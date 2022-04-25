#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string& S)
{
	if (S.size() % 2 == 1)
	{
		return 0;
	}

	if (S.empty())
	{
		return 1;
	}

	stack<char> s;

	for (auto& d : S)
	{
		if (d == '{' || d == '[' || d == '(')
		{
			s.push(d);			
		}
		else
		{
			if (s.empty()) return 0;

			char c = s.top();
			if (d == ')')
			{
				if (c != '(')
				{
					return 0;
				}
			}
			else if (d == ']')
			{
				if (c != '[')
				{
					return 0;
				}

			}
			else if (d == '}')
			{
				if (c != '{')
				{
					return 0;
				}
			}
			s.pop();
		}
	}

	if (s.empty()) return 1;
	else return 0;
}

void main()
{
	string s = "{[()()]}";
	solution(s);
	return;
}


// 坷滚敲肺快眉农 必区