//错误示例
//1、指针位初始化
#include <stdio.h>
int mian()
{
	int *p;//局部变量指针未初始化，默认为随机值
	*p = 20;
	return 0;
}

//2、指针越界访问
#include <stdio.h>
int mian()
{
	int arr[10] = {0};
	int *p = arr;
	int i = 0;
	for(i = 0; i < 12; i++)
	{
		//当指针指向的范围超出数组arr的范围时，p就是野指针
		//*p = i;
		//p++;
		*(p++) = i;
	}
	return 0;
}

//3、指针指向的空间释放
#include <stdio.h>
int* test()
{
	int a = 10;//局部变量a——例空间地址0x0012ff44
	return &a;
}
//销毁a的空间
int main()
{
	int* p = test();//p记住的地址不属于当前程序
	printf("%d\n", *p);//访问的是一块已经被释放的空间
	return 0;
}