
/*
Task description
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Copyright 2009–2022 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>

// my solution
using namespace std;
//
//int solution(vector<int>& A)
//{
//	if (A.empty() == true)
//	{
//		return 0;
//	}
//
//	int minNum = 987654321;
//	int leftSum = 0; // 0, 01, 012, 0123
//	int rightSum = 0; // 4, 43, 432, 4321
//
//	int standNum = 0;
//	int sizeNum = A.size() - 1;
//	
//	while (standNum < sizeNum)
//	{
//		leftSum = 0;
//		rightSum = 0;
//		for (int i = 0; i <= standNum; ++i)
//		{
//			leftSum += A[i];
//		}
//		for (int j = A.size() - 1; j > standNum; --j)
//		{
//			rightSum += A[j];
//		}
//		minNum = min(minNum, abs(leftSum - rightSum));
//		++standNum;
//	}
//	return minNum;
//
//}

/*
	SR = S - SL
	|SL - SR| = SL - S + SL = |2SL - S|

	

*/
int solution(vector<int>& A)
{
	if (A.size() < 2)
	{
		return 0;
	}

	// numeric 헤더 사용
	// 3번째 인자는 초기값 N + accumulate 수열
	int s = accumulate(A.begin(), A.end(), 0);
	int sL = 0;
	int minDiff = INT_MAX;

	for (int i = 0; i < A.size() - 1; ++i)
	{
		sL += A[i];
		int diff = abs(2 * sL - s);
		minDiff = min(minDiff, diff);

	}
	return minDiff;
}


void main()
{
	vector<int> b{3,1,2,4,3};
	solution(b);

	return;
}