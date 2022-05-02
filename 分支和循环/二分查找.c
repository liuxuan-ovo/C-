//编写代码在一个整形有序数组查找具体的某个数，找到打印下标
#include<stdio.h>
int main()
{
	int k = 7;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right)/2;
		if(arr[mid] > k)
		{
			right = mid - 1;
		}
		else if(arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			printf("%d\n",mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}


#include<stdio.h>
#include<string.h>
int binary_search(int arr[],int k,int sz)
{
	
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right)/2;
		if(arr[mid] > k)
		{
			right = mid - 1;
		}
		else if(arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
	
}

//调用
#include<stdio.h>
#include<string.h>
//函数内部求参数部分的数组元素个数要在外面求好传进来
				//本质上arr是一个指针sizeof(arr)==4
int binary_search(int arr[],int k,int sz)
{
	
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right)/2;
		if(arr[mid] > k)
		{
			right = mid - 1;
		}
		else if(arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
	
}
int main()
{
	//二分查找，在一个有序数组中查找具体某个数。如果找到返回这个数的下标，找不到返回-1
	int k = 7;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
						//传递过去的是数组arr首元素的地址             
	int ret = binary_search(arr,k,sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("下标是：%d\n",ret);
	}
	return 0;
}