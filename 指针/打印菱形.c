#define _CRT_SECURE_NO_WARNINGS
//在C语言成屏幕上输出以下图案
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
#include <stdio.h>
int main()
{
	int line = 0;//7
	scanf("%d", &line);
	//打印上半部分
	int i = 0;
	for (i = 0; i < line; i++)
	{
		//打印空格
		int j = 0;
		for (j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		//打印*
		for ( j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for ( i = 0; i < line - 1; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for ( j = 0; j < 2 * (line -i -1)- 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

