//1-100中出现多少数字9

#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for(i=1;i<=100;i++)
	{
		if (i%10 == 9)
		{
			count++;
		}
		if(i/10 == 9)
		{
			count++;
		}
	}
	//9 19 29 39 49 59 69 79 89 99——i%10==9
	//90 91 92 93 94 95 96 97 98 99——i/10==9
	printf("%d\n",count);
	return 0;
}