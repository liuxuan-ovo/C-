#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	//点分十进制
	char arr[] = "198.163.12.255";
	char* p = ".";
	//char arr[] = "liuxuan_ovo@163.com";
	//char* p = "_@.";
	//liuxuan\0ovo@163.com
	char buf[100] = { 0 };
	strcpy(buf, arr);
	//切割buf字符串
	char* ret = NULL;
	for  (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	return 0;
}