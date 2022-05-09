#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void menu()
{
	printf("************************************************\n");
	printf("****0、exit  1、add  2、sub  3、mul  4、div ****\n");
	printf("************************************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个数：>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Add(x,y));
			//冗余的问题
			break;
		case 2:
			printf("请输入两个数：>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Sub(x,y));
			break;
		case 3:
			printf("请输入两个数：>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Mul(x,y));
			break;
		case 4:
			printf("请输入两个数：>");
			scanf("%d%d", &x, &y);
			printf("%d\n", Div(x,y));
			break;
		case 0:
			printf("选择退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}



//指针数组优化
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void menu()
{
	printf("************************************************\n");
	printf("****0、exit  1、add  2、sub  3、mul  4、div ****\n");
	printf("************************************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	//pfArr是一个函数指针数组————转移表
	int (*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		if (input >=1 && input <=4)
		{
			printf("请输入两个值：>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x,y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("选择退出\n");
			break;
		}
		else
		{
			printf("选择错误\n");
		}
	} while (input);
	return 0;
}


//回调函数优化
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void menu()
{
	printf("************************************************\n");
	printf("****0、exit  1、add  2、sub  3、mul  4、div ****\n");
	printf("************************************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
void Calc(int (*pf)(int ,int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个数：>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));
}
int main()
{
	int input = 0;
	
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("选择退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}