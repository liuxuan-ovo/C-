//将数组A中内容和数组B的内容进行交换（数组一样大）
#include<stdio.h>
void Printf(int arr1[], int arr2[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[] = {1,3,5,7,9};
	int arr2[] = {0,2,4,6,8};
	int sz = sizeof(arr1)/sizeof(arr1[0]);
	int i = 0;
	Printf(arr1, arr2, sz);
	for (i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	Printf(arr1,arr2,sz);
	return 0;
}
