#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>

// my solution
using namespace std;
//
// you can write to stdout for debugging purposes, e.g.

int solution(vector<int>& A) {
	// write your code in C++14 (g++ 6.2.0)
	set<int> h_set;

	for_each(A.begin(), A.end(), [&](auto& num) {
		h_set.insert(num);
		});

	return h_set.size();
}

int mySolution(vector<int>& A)
{
	if (A.empty() == true)
	{
		return 0;
	}

	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int size = A.size();


	return size;
}

void main()
{
	vector<int> b{ 1,1,1,1,1,1,1,1 };
	cout << solution(b) << endl;
	cout << mySolution(b) << endl;
	return;
}
