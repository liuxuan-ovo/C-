#include <stdio.h>
int main()
{
	//写一段代码告诉我们当前机器的字节序是什么
	int a = 1;
	//00000000000000000000000000000001——原码=反码=补码
	//00 00 00 01
	//00000001  00000000  00000000  00000000——存储在内存中——小端
	//01 00 00 00
	//00000000  00000000  00000000  00000001——存储在内存中——大端
	//00 00 00 01
	char *p = (char*)&a;
	//指针类型的意义：
	//1、指针类型决定了指针解引用操作符能够访问几个字节：char *p; *p访问1节字节，int *p; *p访问4个字节
	//2、指针类型决定了指针+1，-1，加的或者减的是几个字节；char *p; p+1,跳过1个字符，int *p; p+1跳过一个整型4个字节 
	if (*p == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}

//优化
#include <stdio.h>
int check_sys()
{
	int a = 1;
	char* p = (char*)&a;
	//返回1，小端
	//返回0，大端
	return *p;
}
//在优化
int check_sys()
{
	int a = 1;
	return *(cahr*)&a;
}

int main()
{
	//写一段代码告诉我们当前机器的字节序是什么
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}