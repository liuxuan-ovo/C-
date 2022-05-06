//暴力求解
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,1,2,3,4};//找出单身狗
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);//计算数组的元素个数
	for (i = 0; i < sz; i++)
	{
		//统计arra[i]在arr数组中出现了几次
		int count = 0;//计数器
		int j =  0;
		for (j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("单身狗：%d\n",arr[i]);
			break;
		}
	}
	return 0;
}

//优化
//^按（二进制位）异或——异或满足交换律
//相同为0，相异为1
#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,1,2,3,4};//找出单身狗
	int i = 0;
	int ret = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);//计算数组的元素个数
	for (i = 0; i < sz; i++)
	{
		//统计arra[i]在arr数组中出现了几次
		ret = ret^arr[i];
	}
	printf("单身狗：%d\n",ret);
	return 0;
}