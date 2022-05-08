#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	//数组名是首元素的地址
	//1、sizeof（数组名）——数组名表示整个数组
	//2、&数组名——数组名表示整个数组
	//一维数组
	int a[] = { 1,2,3,4 };//4*4=16
	printf("%d\n", sizeof(a));//sizeof（数组名）——计算的是整个数组总大小——单位是字节——16
	printf("%d\n", sizeof(a + 0));//4/8——数组名这里表示首元素的地址，a+0还是首元素地址，地址的大小就是4/8字节
	printf("%d\n", sizeof(*a));	  //4——数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
	printf("%d\n", sizeof(a + 1));//4/8——数组名这里表示首元素的地址，a+1是第2个元素地址，地址的大小就是4/8字节
	printf("%d\n", sizeof(a[1])); //4 - 第二个元素的大小
	printf("%d\n", sizeof(&a));   //4/8 &a取出的是数组的地址，但数组的地址也是地址，地址的大小就是4/8个字节 
	printf("%d\n", sizeof(*&a));  //16 - &a数组的地址，数组的地址解引用访问的是数组，sizeof计算的是数组的大小，单位是字节
	printf("%d\n", sizeof(&a + 1));//4/8 - &a是数组的地址，&a+1虽然地址跳过整个数组，但还是地址，所以是4/8
	printf("%d\n", sizeof(&a[0])); //4/8 - 第一个元素的地址
	printf("%d\n", sizeof(&a[0] + 1));//4/8 - 
	
	
	//字符数组
	char arr[] = { 'a','b','c','d','e','f'};
	printf("%d\n", sizeof(arr));	  //6 - 计算数组大小 6*1=6
	printf("%d\n", sizeof(arr + 0));//4/8 - arr是首元素地址, a+0还是首元素地址
	printf("%d\n", sizeof(*arr));	  //1 - arr是首元素地址，*arr是首元素，字符大小是1个字节
	printf("%d\n", sizeof(arr[1])); //1
	printf("%d\n", sizeof(&arr));	  //4/8
	printf("%d\n", sizeof(&arr + 1));//4/8
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 第二个元素地址
	
	printf("%d\n", strlen(arr));		//随机值
	printf("%d\n", strlen(arr + 0));	//随机值
	//printf("%d\n", strlen(*arr));	//err非法访问 - *arr = 'a' - 97(字符)，以97地址向后数地址 - 非法访问
	//printf("%d\n", strlen(arr[1]));	//err
	printf("%d\n", strlen(&arr));		//随机值 
	printf("%d\n", strlen(&arr + 1)); //随机值-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值-1
	
	
	//字符数组
	char arr[] = "abcdef";// a b c d e f \0
	printf("%d\n", sizeof(arr));	  //7 - 计算数组大小 7*1=6
	printf("%d\n", sizeof(arr + 0));  //4/8 - arr是首元素地址, arr+0还是首元素地址
	printf("%d\n", sizeof(*arr));	  //1 - arr是首元素地址，*arr是首元素，字符大小是1个字节
	printf("%d\n", sizeof(arr[1]));	  //1 - arr[1]是第二个元素
	printf("%d\n", sizeof(&arr));	  //4/8
	printf("%d\n", sizeof(&arr + 1)); //4/8 - %arr+1跳过整个数组后的地址，但也是地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 第二个元素地址

	printf("%d\n", strlen(arr));		//6 - arr首元素地址,strlen(arr)从首元素开始，字符串长度
	printf("%d\n", strlen(arr + 0));	//6 - arr首元素地址
	//printf("%d\n", strlen(*arr));		//err非法访问 - *arr = 'a' - 97(字符)，以97地址向后数地址 - 非法访问
	//printf("%d\n", strlen(arr[1]));	//err
	printf("%d\n", strlen(&arr));		//6		警告：&arr - 数组的地址 - 数组指针 char(*p)[7] = &arr;my_strlen(const char* str)
	printf("%d\n", strlen(&arr + 1));	//随机值 - 跳过整个数组
	printf("%d\n", strlen(&arr[0] + 1));//5
	
	
	char* p = "abcdef";
	//将常量字符串abcdef中字符a的地址放到p中
	printf("%d\n", sizeof(p));	  //4/8 - 计算指针变量p的大小
	printf("%d\n", sizeof(p + 1));//4/8 - p+1得到字符b的地址
	printf("%d\n", sizeof(*p));	  //1 - *p就是字符串的第一个字符'a'
	printf("%d\n", sizeof(p[0])); //1 - 例：int arr[10]; arr[0] == *(arr+0);  p[0] == *(p+0) == 'a'
	printf("%d\n", sizeof(&p));	  //4/8
	printf("%d\n", sizeof(&p + 1));//4/8 - b的地址 
	printf("%d\n", sizeof(&p[0] + 1));//4/8 - b的地址
	
	printf("%d\n", strlen(p));	  //6
	printf("%d\n", strlen(p + 1));//5
	//printf("%d\n", strlen(*p));	  //err
	//printf("%d\n", strlen(p[0])); //err
	printf("%d\n", strlen(&p));	  //随机值 - p存放的是a的地址，假设a地址：0x0012ff44,p存放44 ff 12 00(小端) - 字符3；
															//假设a:0x12324465,p:65 44 32 12，字符至少为4
	printf("%d\n", strlen(&p + 1));//随机值 - 跳过整个p，更加不可预测 
	printf("%d\n", strlen(&p[0] + 1));//5
	
	
	//二维数组
	int a[3][4] = { 0 };
	
	printf("%p\n",&a[0][0]);
	printf("%p\n",a[0] + 1);
	printf("%p\n",a + 1);
	printf("%p\n",&a[0] + 1);
	
	printf("%d\n", sizeof(a));		//48 - 3*4*4=48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));	//16 - a[0]相当于第一行作为一维数组的数组名，sizeof(a[0])把数组名单独放在sizeof()内，计算第一行的大小
	printf("%d\n", sizeof(a[0] + 1));//4 - a[0]是第一行数组名，数组名此时是首元素地址，其实是第一行第一个元素地址
										   //所以a[0]+1就是第一行第二个元素地址，地址大小是4/8字节
	printf("%d\n", sizeof(*(a[0] + 1)));//4 - *(a[0] + 1)是第一行第二个元素，大小是4个字节
	printf("%d\n", sizeof(a + 1));	//4 - a是二维数组的数组名，没有sizeof(数组名),也没有&(数组名)，所以a是首元素的地址
										//而把二维数组看成一维数组是，二维数组的首元素是他的第一行，a就是第一行(首元素)的地址
										//a+1就是第二行的地址
	printf("%d\n", sizeof(*(a + 1)));//16 - sizeof(a[1]),计算第二行的大小，单位是字节
	printf("%d\n", sizeof(&a[0] + 1));//4 - a[0]第一行数组名，&a[0]第一行地址（数组名取地址），第二行地址
	printf("%d\n", sizeof(*(&a[0] + 1)));//16 - 计算第二行的大小，单位是字节
	printf("%d\n", sizeof(*a));		//16 - a是首元素地址 - 第一行地址，*a就是第一行，sizeof(*a)计算第一行大小
	printf("%d\n", sizeof(a[3]));	//16 - a[3]不会真的访问

}