#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20] = {0};
	system("shutdown -s -t 60");//执行系统命令，一分钟关机
again:
	printf("请注意，你的电脑在一分钟内关机，如果输入：停止关机，就取消关机\n请输入：");
	scanf("%s",input);
	if(strcmp(input,"停止关机") == 0)//strcmp——比较两个字符串
	{
		system("shutdown -a");//执行系统命令，停止关机
	}
	else 
	{
		goto again;
	}
	return 0;
}






#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20] = {0};
	system("shutdown -s -t 60");//执行系统命令，一分钟关机

	printf("请注意，你的电脑在一分钟内关机，如果输入：停止关机，就取消关机\n请输入：");
	while(1)
	{
		scanf("%s",input);
		if(strcmp(input,"停止关机") == 0)//strcmp——比较两个字符串
		{
			system("shutdown -a");//执行系统命令，停止关机
			break;
		}
	
	}
	return 0;
}