#include <stdio.h>
//参数是数组的形式
void print1(int arr[3][5], int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0;j < y; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
//参数是指针的形式
void print2(int (*p)[5],int x, int y)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ",p[i][j]);
			printf("%d ",*(p[i] + j));
			printf("%d ",*(*(p + i) + j));
			printf("%d ",(*(p + i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7} };
	print1(arr,3,5);
	print2(arr,3,5);
	return 0;
}


//示例
#include <stdio.h>
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	int *p = arr;
	for (i = 0; i < 10; i++)
	{
		printf("%d ",p[i]);
		printf("%d ",*(p + i));
		printf("%d ",*(arr + i));
		printf("%d ",arr[i]);//arr[i] == *(arr + i) == *(p + i) == p[i]
	}
	return 0;
}
