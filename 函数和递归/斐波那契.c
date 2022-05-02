//斐波那契数列
//1 1 2 3 5 8 13 21 34 55......
//描述第n个斐波那契数的时候
//迭代
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while(n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
//递归
//例如求Fib(50)时Fib(3)被多次调用，效率低。
//Fib(n)    n<=2    1
			n>2 	Fib(n-1)+Fib(n-2)
#include<stdio.h>
int Fib(int n)
{
	if(n<=2)
		return 1;
	else
		return Fib(n-1)+Fib(n-2);
}
int main()
{
	int n;
	int ret = 0;
	scanf("%d",&n);
	ret = Fib(n);
	printf("%d\n",ret);
	return 0;
}