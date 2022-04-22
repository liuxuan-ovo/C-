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
		printf("this is son1 procass\n");
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
			printf("this is son2 process\n");
			_exit(0);
		}
		else
		{
			printf("this is father process\n");
		}
	}
	return 0;
}

