#include <stdio.h>
int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char* str3 = "hello bit.";
	char* str4 = "hello bit.";
	//相同常量字符串初始化不同数组开辟不同内存块
	if (str1 == str2)
	{
		printf("str1 and str2 are same\n");
	}
	else
		printf("str1 and str2 are not same\n");
	//指针指向同一字符串，实际指向同一块内存
	if (str3 == str4)
	{
		printf("str3 and str4 are same\n");
	}
	else
		printf("str3 and str4 are not same\n");
	return 0;
}
//str1 and str2 are not same
//str3 and str4 are same