//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在
//要求：时间复杂度小于O(N) - 不能遍历
#include <stdio.h>
#include <string.h>
int FindNum(int arr[3][3], int k, int row, int col)
{
	int x = 0;
	int y = col - 1;
	//选择右上角的数字进行判断（只能右上或者左下）
	while (x <= row - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	//没找到
	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}

//优化
#include <stdio.h>
#include <string.h>
int FindNum(int arr[3][3], int k, int* row, int* col)
{
	int x = 0;
	int y = *col - 1;
	//选择右上角的数字进行判断（只能右上或者左下）
	while (x <= *row - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*row = x;
			*col = y;
			return 1;
		}
	}
	//没找到
	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d", x, y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}