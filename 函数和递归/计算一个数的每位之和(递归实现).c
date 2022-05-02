//写一个递归函数DigitSum(n),输入一个非负整数，返回组成他的数字之和
//调用(1729),则应该返回1+7+2+9，他的和是19
//输入：1729，输出：19
//DigitSum(1729)
//DigitSum(172) + 1729%10
//DigitSum(17) + 172%10 + 1729%10
//DigitSum(1) + 17%10 + 172%10 + 1729%10
#include <stdio.h>
int DigitSum(unsigned int num)
{
	if(num > 9)
	{
		ret = DigitSum(num / 10) + num%10;
	}
	return ret;
}
int main()
{
	unsigned int num = 0;
	scanf("%d",&num);
	int ret = DigitSum(num);
	return 0;
}