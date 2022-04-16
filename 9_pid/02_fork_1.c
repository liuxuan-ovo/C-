#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
		perror("fork");
	if(pid == 0)
	{
		printf("this is son process\n");
	}
	else
	{
		printf("this is father process\n");
	}	
	return 0;
}
