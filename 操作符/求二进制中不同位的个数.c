//两个int(32位)整数m和n中的二进制表达中，有多少个位(bit)不同？
#include<stdio.h>
int count_bit_one(int n)
{
	int count = 0;
	while(n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int get_diff_bit(int m, int n)
{
	int tmp = m^n;
	return count_bit_one(tmp);
}
int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	scanf("%d%d",&m,&n);
	count = get_diff_bit(m,n);
	printf("count = %d\n",count);
	return 0;
}