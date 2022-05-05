//求Sn = a+aa+aaa+aaaa+aaaaa	的前五项之和，其中a是一个数字
//例如2+22+222+2222+22222
#include <stdio.h>
#include <string.h> 
#include <assert.h>

int main()
{
	int a = 0;
	int n = 0;
	scanf("%d%d", &a, &n);
	int i = 0;
	int mul = 0;
	int sum = 0;
	for ( i = 0; i < n; i++)
	{
		mul = mul * 10 + a;
		sum += mul;
	}
	printf("%d\n", sum);
	return 0;
}