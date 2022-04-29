//能被4整除，不能被100整除且能被400整除
//方法1
#include<stdio.h>
int main()
{
	int y =  0;
	for(y=1000;y<=2000;y++)
	{
		if((y%4==0&&y%100!=0)||(y%400==0))
			printf("%d ",y);
	}
	return 0;
}

//方法2
#include<stdio.h>
int main()
{
	int y = 0;
	for(y=1000;y<=2000;y++)
	{
		if(y%4 == 0&&y%100 != 0)
			printf("%d ",y);
		else if(y%400 == 0)
		{
			printf("%d ",y);
		}
	}
	
	return 0;
}
//方法三
#include<stdio.h>
int is_leap_year(int y)
{
	if((y%4==0&&y%100!=0)||(y%400==0))
		return 1;
	else
		return 0;
}
int main()
{
	int year = 0;
	for(year=1000;year<=2000;year++)
	{
		if(1 == is_leap_year(year))
			printf("%d ",year);
	}
	return 0;
}
