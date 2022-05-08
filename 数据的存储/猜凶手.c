//凶手必为4个嫌疑犯中的一个
//A说不是我
//B说：是C
//C说：是D
//D说：C在胡说
//已知3个人说了真话，1个人说了假话————1+1+1+0=3
//根据这些信息，写一个程序来确定到底谁是凶手
#include <stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer < 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("凶手是%c", killer);
		}
	}
	return 0;
}