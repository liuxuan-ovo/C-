#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	
	int fd_pipe[2];
	pid_t pid;
	char buf[50]="hello world";
	if(pipe(fd_pipe)<0)
	{	
		printf("pipe\n");
	}

	pid=fork();
	if(pid<0)
	{
		printf("fork\n");
	}
	if(pid==0)
	{
		wait(NULL);
		printf("this is son process\n");
		//exit(0);
		read(fd_pipe[0],buf,sizeof(buf));
		printf("son process buf=%s\n",buf);
		//write(fd_pipe[1],buf,strlen(buf));
	}
	else
	{
		//wait(NULL);
		//memset(buf,0,strlen(buf));
		printf("this is father process\n");
		//read(fd_pipe[0],buf,sizeof(buf));
		//printf("father process buf=%s\n",buf);
		write(fd_pipe[1],buf,strlen(buf));
	
	}

	return 0;
}
