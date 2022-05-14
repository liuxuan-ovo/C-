#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

struct S
{
	char name[20];
	int age;
};

void* my_memcpy(void* dest, const void* src,size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (count--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	if (dest < src)
	{
		//前->后
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//后->前
		while (count--)//20-- = 19
		{
			*((char*)dest + count) = *((char*)src + count);//dest+20-1	
		}
	}
	return ret;
}

//C语言标准：
//memcpy 只要处理 不重叠的内存拷贝就可以
//memmove 处理重叠的内存拷贝
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10};
	int arr2[5] = { 0 };
	struct S arr3[] = { {"张三",20},{"李四",30} };
	struct S arr4[3] = { 0 };
	//my_memcpy(arr4, arr3, sizeof(arr3));
	//memcpy(arr2, arr1,sizeof(arr1));
	//memcpy(arr4, arr3, sizeof(arr3));
	//my_memcpy(arr1 + 2, arr1, 20);//1 2 1 2 1 2 1 8 9 10
	my_memmove(arr1 + 2, arr1 , 20);//处理内存重叠的情况
	return 0;
}