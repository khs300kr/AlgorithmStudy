// BinaryGap

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string ToBinary(int n)
{
	string r;
	while (n != 0)
	{
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

int solution(int N)
{
	string s = ToBinary(N);
	int maxValue = 0;
	int count = 0;

	bool flag = false;
	const int OneDigit = 49;
	const int ZeroDigit = 48;

	for (char& c : s)
	{
		if (c == OneDigit)
		{
			if (flag == false)
			{
				flag = true;
			}
			if (flag == true)
			{
				maxValue = max(maxValue, count);
				count = 0;
			}
		}
		else if (c == ZeroDigit)
		{
			if (flag == true)
			{
				++count;
			}
		}
	}

	return maxValue;
}

void main()
{
	solution(10);
	return;
}
