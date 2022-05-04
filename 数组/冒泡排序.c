#include<stdio.h>
#include<string.h>
void bubble_sort(int arr[],int sz)
{
	//确定冒泡排序的趟数
	int i = 0;
	for(i = 0;i < sz - 1;i++)
	{
		//每一趟冒泡排序
		int j = 0;
		for(j = 0;j < sz - 1 - i;j++)
		{
			int t = 0;
			if(arr[j]>arr[j+1])
			{
				t= arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
int main()
{
	int arr[] = {0,8,9,1,2,3,4,5,6,7};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	//对arr进行排序，排成升序
	//arr是数组，我们对arr进行传参，实际上传递过去的是数组arr数组首元素的地址&arr[0]
	bubble_sort(arr,sz);//冒泡排序函数
	for(i = 0;i < sz;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}


//优化
#include<stdio.h>
#include<string.h>
void bubble_sort(int arr[],int sz)
{
	//确定冒泡排序的趟数
	int i = 0;
	for(i = 0;i < sz - 1;i++)
	{
		int flag = 1;//假设这一趟要排序的数据已经有序								//第一趟
		//每一趟冒泡排序															//9 1 2 3 4 5 6 7 8————flag == 0
		int j = 0;																	//1 9 2 3 4 5 6 7 8
		for(j = 0;j < sz - 1 - i;j++)												//1 2 3 4 5 6 7 8 9
		{
			int t = 0;
			if(arr[j] > arr[j+1])
			{
				t = arr[j];															//第二趟	
				arr[j] = arr[j + 1];												//1 2 3 4 5 6 7 8 9————flag == 1
				arr[j + 1] = t;														
				flag = 0;//本趟要排序的数据其实不完全有序				
			}
		}
		if(flag == 1){break;}	
	}
}
int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	//对arr进行排序，排成升序
	//arr是数组，我们对arr进行传参，实际上传递过去的是数组arr数组首元素的地址&arr[0]
	bubble_sort(arr,sz);//冒泡排序函数
	for(i = 0;i < sz - 1;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

