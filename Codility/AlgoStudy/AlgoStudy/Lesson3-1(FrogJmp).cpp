// you can use includes, for example:
// #include <algorithm>
#include <math.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/*
* 
* #include<math.h>
* ceil : ������ �Ҽ��� �ø���
* floor : �Լ��� ������
* round : �ݿø�
*/

int solution(int X, int Y, int D)
{
	double minJump = double(Y - X) / double(D);

	return ceil(minJump);
}

