#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int var = 10;

int main(int argc, char *argv[])
{
	pid_t pid;
	int num = 9;
	pid=vfork();
	if(pid<0)
		perror("fork");
	if(pid==0)
	{
		var++;
		num++;
		printf("int son process var=%d,num=%d\n",var,num);
		_exit(0);
	}
	else
	{
		printf("in father process var=%d,num=%d\n",var,num);
	}
	printf("common code area\n");
	return 0;
}
