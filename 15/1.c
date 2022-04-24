#include<stdio.h>
#include<arpa/inet.h>

int main()
{
	int a = 0x01020304;
	short int b = 0x0102;
	printf("htonl(%08x) = %08x\n",a,hotnl(a));
	printf("htonl(%08x) = %03x\n",b,hotnl(b));
	return 0;
}