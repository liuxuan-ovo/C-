#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	//比较
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;//相等
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);//返回><0
	//if (*str1 > *str2)
	//	return 1;//大于
	//else
	//	return -1;//小于
}
int main()
{
	char* p1 = "abcdef";
	char* p2 = "abqwe";
	int ret = my_strcmp(p1, p2);
	printf("ret = %d\n", ret);
	//strcmp比较字符串
	//比较的是首地址字符串的ASCLL值，若相等，则比较下一对
	/*if (strcmp(p1,p2) > 0)
	{
		printf("p1 > p2\n");
	}
	else if (strcmp(p1, p2) == 0)
	{
		printf("p1 == p2\n");
	}
	else if (strcmp(p1, p2) < 0)
	{
		printf("p1 < p2\n");
	}*/
	return 0;
}