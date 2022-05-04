//创建一个整型数组，完成对数组的操作
//实现函数Init初始化数组全为0
//实现Printf()打印数组的每个元素
//实现receive()函数实现函数的逆算
#include<stdio.h>
void Init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void Printf(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}

}
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	//Init(arr,sz);//对数组初始化为0
	Printf(arr, sz);//打印
	Reverse(arr, sz);
	Printf(arr, sz);//打印
	return 0;
}
