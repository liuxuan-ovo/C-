//一
#include <stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};
	int *ptr = (int *)(&a + 1);//(&a + 1)跳过整个数组
	printf("%d,%d\n",*(a+1),*(ptr - 1))；
					//a首元素地址
}
//2，5


//二
struct Test
{
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设 p的值为0x100000。如下表表达式的值分别为多少？
//已知结构体Test类型的变量大小是20个字节
int main()
{
	//p = (struct Text*)0x100000;//指针变量p,存放的是0x100000
	printf("%p\n",p + 0x1);//p是结构体指针+1跳过一个结构体（20字节）
	printf("%p\n",(unsigned long)p + 0x1);//(unsigned long)转换成整数+1
	printf("%p\n",(unsigned int*)p + 0x1);//(unsigned int*)转换成无符号整型，+1，跳过4个字节等于地址+4
}
//0x00100014
//0x00100001
//0x00100004
//指针+-整形取决于指针类型


//三
int main()
{
	int a[4] = {1,2,3,4};
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x",ptr1[-1], *ptr2);
	return 0;
}
//0x4		0x02000000——————详细讲解OneNote指针进阶


//四
int main()
{
	int a[3][2] = { (0,1),(2,3),(4,5) };
		//逗号表达式		{1,3,5}
	int* p;
	p = a[0];//（首元素的地址'1'的地址）
	printf("%d",p[0]);
	return 0;
}
//1


//五
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}
//FFFFFFFC    -4————————详解见OneNote指针进阶


//六
int main()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));//*(aa + 1) == aa[1] - 第二行首元素地址
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
}
//10	5

//七
int main()
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;//char* *pa = a
	pa++;
	printf("%s\n",*pa);
	return 0;
}
//at


//八
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
//POINT    ER	 ST		EW
