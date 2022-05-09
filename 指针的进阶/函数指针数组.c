#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//指针数组
	int* arr[5];
	int (*p)(int, int) = Add;
	//需要一个数组，这个数组可以存放4个函数地址————指针数组的函数
	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n",parr[i](2,3));//5 6 -1 0
	}

	return 0;
}
