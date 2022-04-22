#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char command1[256];
	char command2[256];
	int fd[2];
	pid_t pid;
	int ret;
	printf("enter the command1:\n");
	fgets(command1,256,stdin);
	printf("enter the command2:\n");
	fgets(command2,256,stdin);
	command1[strlen(command1)-1]='\0';
	command2[strlen(command2)-1]='\0';
	pid = fork();
	if(pid<0)
 	perror("fork");
 	if(pid==0)
 	{
  		execlp(command1,command2,NULL);
  		exit(2);
 	}
 	else
 	{
 		 wait(0);
 		 int status;
 		 printf("this is father\n");
 		 if(WIFEXITED(status)!=0)
 			  printf("son return %d\n",WEXITSTATUS(status));
 	}
 	return 0;
}
