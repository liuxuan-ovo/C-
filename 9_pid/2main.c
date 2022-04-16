#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int a;
int main(int argc, char *argv[])
{
	int b;
	pid_t pid;
	if(pid<0)
		printf("fork");
	if(pid==0)
	{
		a++;
		b++;
		printf("the son a= %d,b=%d\n",a,b);
	}
	else
	{
		
		printf("father\n");
	}
	return 0;
}
