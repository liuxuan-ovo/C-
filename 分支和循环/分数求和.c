#include<stdio.h>

int main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for(i=1;i<100;i++)
	{
		sum += flag*1.0/i;//必须有浮点数，否则结果是1-0+0-0+0
		flag = -flag;
	}
	printf("%lf\n",sum);
	return 0;
}