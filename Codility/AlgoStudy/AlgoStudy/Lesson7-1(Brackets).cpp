#include <algorithm>
#include <stack>
#include <string>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string& S)
{
	stack<char> BracketStack;

	for (auto d : S)
	{
		if (d == '{' || d == '[' || d == '(')
		{
			BracketStack.push(d);
		}
		else if (d == '}' || d == ']' || d == ')')
		{
			auto c = BracketStack.top();

		}
	}
	return 0;

}

void main()
{
	string s = "{[()()]}";
	solution(s);
	return;
}


// 坷滚敲肺快眉农 必区