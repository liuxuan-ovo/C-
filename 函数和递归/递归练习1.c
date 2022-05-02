//练习1
//接受一个整型值，按照顺序打印打印它的每一位。例：输入：1234 输出：1 2 3 4
#include<stdio.h>
void print(int n)
{
	if(n>9)
	{
		print(n/10);
	}
	printf("%d ",n%10);
}
int main()
{
	int num = 1234;
	print(num);
	//print(1234)
	//print(123) 4
	//print(12) 3 4
	//print(1) 2 3 4
	return 0;
}

//练习2
//编写函数不允许创建临时变量，求字符串的长度
#include<stdio.h>
//递归的方法
//把大事化小
//my_strlen("bit")
//1+my_strlen("it")
//1+1+my_strlen("t")
//1+1+1+0
int my_strlen(char* str)
{
	if(*str != '\0')
		return 1+my_strlen(str+1);
	else
		return 0;
}
//平常方法——计数器方式
int my_strlen(char* arr)
{
	int count = 0;
	while(*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}
//指针方法
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while(end != '\0')
	{
		end++;
	}
	return end - start;
}


int main()
{
	char arr[] = "bit";
	//int len = strlen(arr;);   //求字符串长度
	//printf("%d\n",len);

	//模拟实现一个strlen函数
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len = %d\n",len);
	return 0;
}