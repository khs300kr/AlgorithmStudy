/*
Task description
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Copyright 2009–2022 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int solution(vector<int>& A)
{
	if (A.empty() == true)
	{
		return 1;
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != i + 1)
		{
			return i + 1;
		}
	}
	return (A.size() + 1);
}



/*
소감 : description 이해가 어려웠다 예외처리가 empty 였을때 1 인거와 마지막 숫자가 없을때라는 점....?

*/