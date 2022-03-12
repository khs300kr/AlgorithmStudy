

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
	// duplicate check
	sort(A.begin(), A.end());
	bool hasDuplicate = adjacent_find(A.begin(), A.end()) != A.end();
	if (hasDuplicate == true)
	{
		return 0;
	}

	int sizeOfvec = A.size();
	int s = std::accumulate(A.begin(), A.end(), 0);
	int realSum = sizeOfvec * (sizeOfvec + 1) / 2;
	return realSum != s ? 0 : 1;
}