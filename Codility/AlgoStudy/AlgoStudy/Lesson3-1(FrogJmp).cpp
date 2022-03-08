// you can use includes, for example:
// #include <algorithm>
#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
* 
* #include<math.h>
* ceil : 무조건 소수점 올린다
* floor : 함수를 버린다
* round : 반올림
*/

int solution(int X, int Y, int D)
{
	double minJump = double(Y - X) / double(D);

	return ceil(minJump);
}

