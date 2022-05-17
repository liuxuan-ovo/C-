#include <stdio.h>
#include <assert.h>
int my_strlen(const char *str)
{
	int count = 0;
	assert(str != NULL);//保证指针的有效性
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//unsigned int - size_t - 无符号
size_t com_strlen(const char* str)//库函数
{

}


int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n",len);
	return 0;
}
