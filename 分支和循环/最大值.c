//输入a b c,求a b c 中的最大值
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b)
	{
		int q = a;
		a = b;
		b = q;
	}
	if(a<c)
	{
		int q = a;
		a = c;
		c = q;
	}
	if(b<c)
	{
		int q = b;
		b = c;
		c = q;
	}
	printf("%d %d %d",a,b,c);
	system("pause");
}





#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int max = arr[0];
	int i = 0;
	int sz = sizeof(arr)/sizeof(arr[0]);
	for(i=1;i<sz;i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	printf("max = %d\n",max);
	return 0;

}