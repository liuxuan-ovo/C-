//递归
//Fac(n)  n<=1   1
		  n> 1   n*Fac(n-1)

#include<stdio.h>
int Fac(int n)
{
	if(n<=1)
		return 1;
	else
		return n*Fac(n-1);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d",&n);
	ret = Fac(n);
	printf("%d\n",ret);
	return 0;
}

//非递归
#include<stdio.h>
int Fac1(int n)
{
	int i = 0;
	int ret = 1;
	for(i=1;i<=n;i++)
	{
		ret*=i;
	}
	return ret;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d",&n);
	ret = Fac1(n);
	printf("%d\n",ret);
	return 0;
}