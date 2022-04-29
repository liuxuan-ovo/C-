#include<stdio.h>
#include<string.h>

int main()
{
	char passwork[20] = {0};
	int i = 0;
	for(i=0;i<3;i++)
	{
		printf("请输入密码：");
		scanf("%s",passwork);
		if(strcmp(passwork,"123456") == 0)
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if(i == 3)
	{
		printf("输入失败\n");
	}
	return 0;
}