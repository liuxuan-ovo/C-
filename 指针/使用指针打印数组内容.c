//写一个函数打印arr数组的内容，不使用数组下标，使用指针。arr是一个整形一维数组。
#include <stdio.h>
void print(int *p, int sz)
{
	int i = 0;
	for(i = 0; i < sz; i++)
	{
		printf("%d ",*(p +i));
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	print(arr,sz);
	return 0;
}