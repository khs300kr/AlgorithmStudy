#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <functional>

// my solution
using namespace std;

int solution(vector<int>& A)
{
	int size = A.size();
	sort(A.begin(), A.end());

	int sumA = A[size - 1] * A[0] * A[1];
	int sumB = A[size - 1] * A[size - 2] * A[size - 3];
	int maxN = max(sumA, sumB);

	return maxN;

}