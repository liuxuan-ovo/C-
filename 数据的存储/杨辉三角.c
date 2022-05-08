#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define X 10
#define Y 10

int main()
{
	int arr[X][Y] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
			/*if (i == j)
			{
				arr[i][j] = 1;
			}*/
			if (i >= 2 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	/*for (i = 0; i < Y; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/
	for (i = 0; i < Y; i++)
	{
		//打印空格
		int j = 0;
		for (j = 0; j < Y - i - 1; j++)
		{
			printf(" ");
		}
		//打印arr
		for (j = 0; j < i + 1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;

}



