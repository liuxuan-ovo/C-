//《素数求解的n种境界》
//判断i是否位素数————只能被1和本身整除
//素数判断法则
//1试除法（方法1，2，3）
//产生2->i-1
//方法1
#include<stdio.h>
int main()
{
	int i = 0;	
	int count = 0;
	for(i=100;i<=200;i++)
	{
		int j = 0;
		for(j=2;j<i;j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j==i)
		{
			count++;
			printf("%d ",i);
		}	
	}
	printf("\ncount = %d\n",count);
	return 0;
}

//方法2
#include<stdio.h>
#include<math.h>
int main()
{
	//sqrt——开平方的数学库函数
	int i = 0;
	int count = 0;
	for(i=100;i<=200;i++)
	{
		int j = 0;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j>sqrt(i))
		{
			count++;
			printf("%d ",i);
		}	
	}
	printf("\ncount = %d\n",count);
	return 0;
}

//方法3
//偶数不可能是素数
#include<stdio.h>
#include<math.h>
int main()
{
	//sqrt——开平方的数学库函数
	int i = 0;
	int count = 0;
	for(i=101;i<=200;i+=2)
	{
		int j = 0;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j == 0)
			{
				break;
			}
		}
		if(j>sqrt(i))
		{
			count++;
			printf("%d ",i);
		}	
	}
	printf("\ncount = %d\n",count);
	return 0;
}

//方法四
#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int j;
	for(j=2;j<=sqrt(n);j++)
	{
		if(n%j == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int i = 0;	
	for(i=100;i<=200;i++)
	{
		if(is_prime(i) == 1)
			printf("%d ",i);	
	}
	return 0;
}
