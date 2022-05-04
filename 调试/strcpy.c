//模拟实现库函数strcpy
//10分——>6分
#include <stdio.h>
void my_strcpy(char *dest, char *src)//dest目的地  src源
{
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;//'\0'
}
int main()
{
	//strcpy
	//字符串拷贝
	char arr1[] = "###############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);//arr2->arr1
	printf("%s\n", arr1);
	return 0;
}

//7分
#include <stdio.h>
void my_strcpy(char *dest, char *src)
{
	//*解引用，=赋值， ++
	while(*dest++ = *src++)//'0'ASCLL为0
	{
		;
	}
}
int main()
{
	char arr1[] = "###############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//优化
#include <stdio.h>
void my_strcpy(char *dest, char *src)
{
	if (dest != NULL && src != NULL)//判断是否为空指针，但是没有报错
	{
		while(*dest++ = *src++)//'0'ASCLL为0
		{
			;
		}
	}
}

int main()
{
	char arr1[] = "###############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//8分
#include <stdio.h>
#include <assert.h>
void my_strcpy(char *dest, char *src)
{
	assert(dest != NULL);//断言,报错
	assert(src != NULL);//断言,报错

	while(*dest++ = *src++)//'0'ASCLL为0
	{
		;
	}
}

int main()
{
	char arr1[] = "###############";
	char arr2[] = "bit";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

//10分
#include <stdio.h>
#include <assert.h>
char* my_strcpy(char *dest,const char *src)//const修饰 *src无法改变
{
	char *ret = dest;//将dest首地址传给ret
	assert(dest != NULL);//断言,报错
	assert(src != NULL);//断言,报错
	//把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
	while(*dest++ = *src++)//'0'ASCLL为0
	{
		;
	}
	return ret;//返回目的地起始地址
}

int main()
{
	char arr1[] = "###############";
	char arr2[] = "bit";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}

