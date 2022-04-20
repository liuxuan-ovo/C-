#include<stdio.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid<0)
		perror("fork");
	if(pid==0)
	{
		int i=0;
		for(i=0;i<5;i++)
		{
			printf("this is son process\n");
			sleep(1);
		}
	}
	else
	{
		printf("this is father process\n");
		sleep(2);
		printf("kill sun process now\n");
		kill(getpid(),SIGINT);
	}
	return 0;
	
}
