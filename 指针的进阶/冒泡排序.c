#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp_int(const void* e1, const void *e2)
{
	//比较两个整形值的
	return *(int*)e1 - *(int*)e2;
}

int cmp_float(const void* e1,const void* e2)
{
	/*if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 < *(float*)e2)
		return -1;
	else
		return 1;*/
	return ((int)(*(float*)e1 - *(float*)e2));
}

struct stu
{
	char name[20];
	int age;
};

int cmp_stu_by_age(const void*e1, const void*e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{
	//比较名字就是比较字符串
	//字符串比较不能直接用><=来比较，应该用strcmp函数
	return strcmp(((struct	stu*)e1)->name, ((struct stu*)e2)->name);
}

void test1()
{
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	//第一个参数：待排序数组的首元素个数
	//第二个参数：待排序数组的元素个数
	//第三个参数：待排序数组的每个元素的大小————范围是字节
	//第四个参数：是函数指针，比较两个元素的所用函数的地址——这个函数使用者自己实现
	//			  函数指针的	两个参数是：待比较的两个元素的地址
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}


void test3()
{
	struct stu s[3] = { {"zhangsan", 20}, {"lisi", 30}, {"wnagsu", 10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d\n",s[i].name,s[i].age);
	}
}

void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
//自己写一个冒泡函数
//实现bubble_sort函数的程序员，他是否知道未来排序的数据类型——不知道
//程序员也不知道，待比较两个元素的类型
void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//每一趟比较的对数
		int j = 0;
		for ( j = 0; j < sz - i - 1; j++)
		{
			//两个元素的比较
			//(char*)强制转换成char型1个字节，+width(宽度);j为第几个元素
			if (cmp((char*)base+j*width, (char*)base + (j + 1)*width) > 0)
			{
				//交换
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
void test4()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//使用bubble_sort的程序员一定知道自己排序的是什么数据
	//就应该知道如何比较待排序数组中的元素
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}

void test5()
{
	struct stu s[3] = { {"zhangsan", 20}, {"lisi", 30}, {"wnagsu", 10} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	//bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}
int main()
{
	
	//test1();//整数数组
	//test2();//浮点数数组
	test3();//结构体数组
	//test4();
	test5();
	return 0;
}
//void* 类型的指针 可以接收任意类型的地址
//void* 类型的指针 不能进行解引用操作
//void* 类型的指针 不能进行+-整数的操作
//void qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2));
//						,函数的长短	,函数的宽度	 ,
//e1 < e2   返回小于0的数
//e1 = e2   返回0
//e1 > e2   返回大于0的数