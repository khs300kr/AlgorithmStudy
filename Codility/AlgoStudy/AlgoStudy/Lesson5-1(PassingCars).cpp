#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>

// my solution
using namespace std;
//
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A)
{
	if (A.empty() == true)
	{
		return 0;
	}

	int count = 0;
	int sE = 0;

	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] == 0)
		{
			++sE;
		}
		else if (A[i] == 1)
		{
			count += sE;
		}
		if (count > 1000000000)
		{
			return -1;
		}
	}
	return count;
}




void main()
{
	vector<int> b{ 0, 1, 0, 1, 1 };
	solution(b);
	return;
}