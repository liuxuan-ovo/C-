#include<stdio.h>
#include<arpa/inet.h>

int main()
{
	int a = 0x01020304;
	short int b = 0x0102;
	printf("htonl(%08x) = %08x\n",a,htonl(a));
	printf("htonl(%04x) = %04x\n",b,htons(b));
	return 0;
}
