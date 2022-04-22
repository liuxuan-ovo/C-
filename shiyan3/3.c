#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int filedes[3];
	pid_t pid1,pid2;
	char send1[100] = "Child 1 is sending a message!";
	char send2[100] = "Child 2 is sending a message!";

	if(pipe(filedes) < 0)
		perror("pipe");
	pid1 = vfork();
	if(pid1<0)
	{
		perror("fork");
		//exit(-1);
	}
	if(pid1==0)
	{
		//printf("this is son1 process");
		write(filedes[1],send1,sizeof(send1));
		_exit(0);
	}
	else
	{
		pid2 = vfork();
		if(pid2<0)
			perror("fork");
			//exit(-1);
		if(pid2==0)
		{	
			write(filedes[1],send2,sizeof(send2));
			_exit(0);
		}
		else
		{
			//wait(NULL);
			//memset(send1,0,sizeof(send1));
			read(filedes[0],send1,sizeof(send1));
			
			printf("P1=%s\n",send1);
			wait(0);
			//memset(send2,0,sizeof(send2));
			read(filedes[0],send2,sizeof(send2));
			printf("P2=%s\n",send2);
			exit(0);
		}
	}
	return 0;
}
