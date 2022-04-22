#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	pid_t pid1,pid2;
	pid1=vfork();
	if(pid1<0)
		perror("fork");
	if(pid1==0)
	{
		printf("b\n");
		_exit(0);
	}
	else
	{
		pid2=vfork();
		if(pid2<0)
		{
			perror("fork");
		}
		if(pid2==0)
		{
			printf("c\n");
			_exit(0);
		}
		else
		{
			printf("a\n");
		}
	}
	return 0;
}

