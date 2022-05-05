//求出1~100000之间的所有“自幂数”并输出
//“自幂数”是指一个n位数，其各位数字的n次方之和等于它本身
//如153 = 1^3 + 5^3 + 3^3 ,则153是一个水仙花数
#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//判断i是否位水仙花数（自幂数）
		//1、计算i的位数 - n位数
		int n = 1;
		int t = i;
		int sum = 0;
		while (t /= 10)
		{
			n++;
		}
		//2、计算i的每一位n次方之和sum
		t = i;
		while (t)
		{
			sum += pow(t % 10, n);//数的n次方
			t /= 10;
		}
		//3、比较i == sum
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
