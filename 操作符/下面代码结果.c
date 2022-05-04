#include <stdio.h>
int main()
{
	int i = 1;
	int ret = (++i)+(++i)+(++i);
	printf("ret = %d\n",ret);
	ret 0;
}
//程序错误

#include <stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5};//int 4个字节*5
	short *p = (short*)arr;//short 2个字节
	int i = 0;
	for(i = 0; i < 4; i++)//总共前进2*4=8个字节
	{
		*(p + i) = 0;
	}
	for(i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	ret 0;
}
//0 0 3 4 5
 
#include <stdio.h>
int main()
{
	int a = 0x11223344;		//存放44 33 22 11	4个字节
	char *pc = (char*)&a;	
	*pc = 0;				//访问1个字节
	printf("%x\n",a);		//还原11 22 33 00
	return 0;
}
//11223300
 
#include<stdio.h>
int i;//全局变量——不初始化，默认是0
int main()
{
	i--;
	//-1
	//10000000000000000000000000000001——原码
	//11111111111111111111111111111110——反码
	//11111111111111111111111111111111——补码
	//无符号数——正数——>补码=原码
	if (i < sizeof(i))//szieof()计算变量/类型所占内存大小 >= 0无符号数
	{
		printf(">");
	}
	else
	{
		printf("<");
	}
	return 0;
}
//>

#include <stdio.h>
int main()
{
	int a, b, c;
	a = 5;
	c = ++a;					//c = 6 a = 6
	b = ++c, c++, ++a, a++;		//b = 7 c = 8 a = 8		复制运算符=优先级>逗号运算符b=++c
	b += a++ + c;				//b = 23 a = 9 c = 8
	printf("a = %d b = %d c = %d\n",a,b,c);
}
//a = 9 b = 23 c = 8


