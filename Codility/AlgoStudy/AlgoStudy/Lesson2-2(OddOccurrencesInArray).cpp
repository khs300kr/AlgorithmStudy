
#include <iostream>
#include <algorithm>
#include <vector>

// my solution
using namespace std;

int solution(vector<int>& A)
{
	if (A.empty() == true)
	{
		return 0;
	}

	vector<int> B(A.size());
	copy(A.begin(), A.end(), B.begin());

	B.erase(unique(B.begin(), B.end()),B.end());
	for (auto d : B)
	{
		// count는 무거운 루프...
		int myCount = count(A.begin(), A.end(), d);
		if (myCount == 1)
		{
			return d;
		}
	}
}

// 홀수번째를 찾는다... 인덱싱해서
int solution(vector<int>& A)
{
	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i = i + 2) 
	{
		if (A[i] != A[i + 1]) 
		{
			return A[i];
		}
	}
}


void main()
{
	vector<int> a{ 9, 3, 9, 3, 9, 7, 9 };

	cout << solution(a) << endl;
	return;
}