//不使用第三个变量
//加减法
#include <stdio.h>
#include <limits.h>
int main()
{
	int a = 3;
	int b = 5;
	//INT_MAX; 2147483647
	printf("交换前：a = %d b = %d\n",a,b);
	//溢出的问题
	//int -4个字节 -32个bit位 -最大值
	a = a + b;
	b = a - b;//a-b还是原来的b
	a = a - b;
	printf("交换后：a = %d b = %d\n",a,b);
	return 0;
}

//优化
//^按（二进制位）异或——异或满足交换律
//相同为0，相异为1
#include <stdio.h>
int main()
{
	int a = 3;
	int b = 5;
	printf("交换前：a = %d b = %d\n",a,b);		a=3						5
	a = a^b;									011		110		110		101
	b = a^b;									b=5						3
	a = a^b;									101		101		011		011
	printf("交换后：a = %d b = %d\n",a,b);
	return 0;
}
