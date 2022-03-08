/*
Task description
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Write a function:

vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

	A = [3, 8, 9, 7, 6]
	K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

	[3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
	[6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
	[7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

	A = [0, 0, 0]
	K = 1
the function should return [0, 0, 0]

Given

	A = [1, 2, 3, 4]
	K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.

Copyright 2009–2022 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/


#include <iostream>
#include <algorithm>
#include <vector>

// my solution
using namespace std;
//
//void initVec(vector<int>& A, int S)
//{
//	A.clear();
//	for (int i = 0; i < S; ++i)
//	{
//		A.emplace_back(0);
//	}
//}
//
//vector<int> solution(vector<int>& A, int K)
//{
//	vector<int> B;
//	B.reserve(A.size());
//
//	// write your code in C++14 (g++ 6.2.0)
//	for (int i = 0; i < K; ++i)
//	{
//		initVec(B, A.size());
//		for (int j = 0; j < A.size(); ++j)
//		{
//			if (j == A.size() - 1)
//			{
//				B[0] = A[j];
//			}
//			else
//			{
//				B[j + 1] = A[j];
//			}
//		}
//		A.swap(B);
//	}
//
//	return A;
//}
//

vector<int> solution(vector<int>& A, int K)
{
	if (A.empty() || A.size() == 1)
	{
		return A;
	}

	// 몇번을 반복해도 K 횟수니까
	K = K % A.size();

	// K번이 그대로면...
	if (K == 0)
	{
		return A;
	}

	// rotate 검색	

	// simple rotation to the left
	//std::rotate(v.begin(), v.begin() + 1, v.end());

	// simple rotation to the right
	//std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

	std::rotate(A.rbegin(), A.rbegin() + K, A.rend());
	return A;
}

void main()
{
	vector<int> a{ 3,8,9,7,6 };
	int k = 3;

	solution(a, 3);
	return;
}