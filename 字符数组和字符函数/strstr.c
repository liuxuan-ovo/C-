//strstr - 查找字符串
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = NULL;
	char* s2 = NULL;
	char* cur = (char *)p1;
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	//一次匹配失败后要进行下一次匹配
	while (*cur)
	{
		s1 = cur;//匹配错误后s1回到下一次开始的位置
		s2 = (char *)p2;//每次配对错误回到初始位置
		//while(*s1 && *s1 && !(*s1 - *s2))
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		//if(!*s2)
		if (*s2 == '\0')
		{
			return cur;//找到子串
		}
		//if(*s1 == '\0')
		//	return NULL;//p2比p1长，提前终止
		cur++;//每次配对错误p1地址+1，重新开始配对
	}
	return NULL;//找不到子串
}

//优化KMP算法

int main()
{
	char* p1 = "abbbcdef";
	char* p2 = "bbc";
	char* ret = my_strstr(p1, p2);
	//char* ret = strstr(p1, p2);//返回p1中p2字符串第一次出现的起始位置
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
		printf("%s\n", ret);
	return 0;
}