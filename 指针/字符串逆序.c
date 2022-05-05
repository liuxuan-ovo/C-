//写一个函数，可以逆序一个字符串的内容

#include <stdio.h>
#include <string.h> 
#include <assert.h>

void reverse(char* str)
{
	assert(str);
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = *left;
		left++;
		right--;
	}
}

int main()
{
	char arr[100] = { 0 };
	//scanf("%s", arr);
	gets(arr);//取一行
	reverse(arr);
	printf("字符串逆序：%s",arr);
	return 0;
}