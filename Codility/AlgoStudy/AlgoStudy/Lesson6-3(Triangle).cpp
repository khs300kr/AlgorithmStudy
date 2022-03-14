#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <math.h>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N)
{
	string strNum = to_string(N);
	string tempStr;
	int retNum = 0;

	for (int i = 0; i < strNum.length(); ++i)
	{
		tempStr = to_string(N);
		if (tempStr[i] == '5')
		{
			tempStr.erase(find(tempStr.begin() + i, tempStr.end(), '5'));
			retNum = max(retNum, stoi(tempStr));
		}
	}

	return retNum;
}

void main()
{
	//vector<int> b{ 2147483644,2147483645,2147483646 };
	solution(-5859);
	return;
}


// 坷滚敲肺快眉农 必区