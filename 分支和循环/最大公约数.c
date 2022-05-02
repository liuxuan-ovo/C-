%include<stdio.h>
//辗转相除法
int main()
{
	int m = 24;
	int n = 18;
	int r = 0;
	while(m%n)
	{
		r = m%n;
		m = n;
		n = r;
	}
	printf("%d\n",n);
	return 0;
}