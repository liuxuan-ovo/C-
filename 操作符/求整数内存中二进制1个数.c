//求一个整数存储在内存中二进制1的个数
//方法1
//存在缺陷，复数的时候失效
#include<stdio.h>
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d",&num);
	//统计num补码中有几个1
	while (num)
	{
		if (num % 2 == 1)	//十进制由%10/10得每一位		二进制%2/2
			count++;
		num = num / 2;
	}
	printf("%d\n",count);
	return 0;
}
//在方法1基础上优化
#include <stdio.h>
int count_bit_one(unsigned int n)//转换成无符号数
{
	int count = 0;
	while(n)
	{
		if(n % 2 == 1)
		{
			count++;
		}
		n = n / 2; 
	}
	return count;
}
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d",&num);
	count = count_bit_one(num);
	printf("%d\n",count);
	return 0;
}

//优化
//方法2
//32bit
//num & 1 == 1
//00000000000000000000000000000011
//00000000000000000000000000000001
#include<stdio.h>
int main()
{
	int num = 0;
	int i = 0;
	int count = 0;
	scanf("%d",&num);
	//统计num补码中有几个1
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1)) 
		{
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}

//方法3————最高效写法
#include<stdio.h>
int main()
{
	int n = 0;
	int count = 0;
	scanf("%d",&n);
	//统计n补码中有几个1
	while (n)
	{
		count++;
		n = n&(n - 1);
	}
	printf("%d\n",count);
	return 0;
}
//n = n&(n-1)
//13
//1101 n
//1100 n-1

//1100 n
//1011 n-1

//1000 n
//0111 n-1

//0000 n
