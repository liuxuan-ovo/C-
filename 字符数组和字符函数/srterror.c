//错误信息函数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
{
	//错误码	  错误信息
	//0 -	  No error
	//1 -	  Operation not permitted
	//2 -	  No such file or directory
	//......
	//errno 是一个全局的错误码的变量
	//当C语言的库函数正在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中

	//char* str = strerror(2);
	//printf("%s\n", str);

	//打开文件
	FILE* pf = fopen("test.txt", "r");//以只读的方式打开test.txt
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	return 0;
}