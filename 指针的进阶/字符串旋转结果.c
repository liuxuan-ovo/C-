//写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串
//例如：给定S1=AABCD和S2=BCDAA，返回1
//给定S1=abcd和S2=ABCD，返回0
//AABCD左旋一个字节得到ABCDA
//AABCD左旋两个字节得到BCDAA
//AABCD右旋一个字节得到DAABC
#include <stdio.h>
#include <string.h>
#include <assert.h>
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);

	reverse(arr, arr + k - 1);//逆序左边
	reverse(arr + k, arr + len - 1);//逆序右边
	reverse(arr, arr + len - 1);//逆序整体
}
//穷举法
int is_left_move(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(s1, 1);//每次左旋一个
		int ret = strcmp(s1, s2);//知道s1,s2相等
		if (ret == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}


//优化
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
int is_left_move(char* s1, char* s2)
{
	assert(s1);
	assert(s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	//1、在s1字符串中追加一个s1字符串
	//strcat(s1,s1);//err - 直到找到\0才结束追加
	strncat(s1, s1, len1);//abcdefabcdef
	//2、判断s2指向的字符串是否是s1指向的字符串的子串
	//strstr - 找子串的
	char* ret = strstr(s1, s2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}