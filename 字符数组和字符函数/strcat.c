
#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, char* src)
{
	assert(dest && src);
	char* ret = dest;
	//1、找到目的字符串的'\0'
	while (*dest != '\0')
	{
		dest++;
	}
	//2、追加(就是strcpy)
	while (*dest++ = *src++)
	{
		;
	}
	return ret;

}
int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	//strcat(arr1, arr2);//从目标空间的\0开始追加
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}