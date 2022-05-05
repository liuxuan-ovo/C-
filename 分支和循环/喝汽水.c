//1元1瓶汽水，2个空瓶可以换1瓶汽水
//问：20元钱能喝多少瓶汽水
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//买回来的汽水喝掉
	total = money;
	empty = money;
	//换回来的汽水
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("喝了%d瓶汽水", total);
	return 0;
}