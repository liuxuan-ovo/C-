#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void neum()//菜单
{
	printf("--------------------------\n");
	printf("-----1.play   0.exit------\n");
	printf("--------------------------\n");
}
void game()
{
	int ret = 0;
	int gess = 0;
	//1.生成一个随机数字
	
	ret = rand()%100+1;//生成1-100随机数   rand()生成随机生成0-32767
	//printf("%d\n",ret);
	//2.猜数字
	while (1)
	{
		printf("猜猜数字：");
		scanf("%d",&gess);
		if (gess < ret)
		{
			printf("小了\n");
		}
		else if (gess > ret)
		{
			printf("大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//调用rand前设置随机数生成器，设置一个随机起点
									//拿时间戳来设置随机数的生成起始点
	do
	{
		neum();//菜单
		printf("请选择：");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			printf("选择退出\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	
	return 0;
}