#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct _msg
{
	long types;
	char mtext[500];
}MSG;
int main(int argc, char *argv[])
{
	pid_t client;
	client = fork();
	if(client < 0)
	{
		perror("fork");
	}
	if(client == 0)
	{
		int msgqid;
		int i;
		MSG msg;
		msgqid = msgget(75,IPC_CREAT|0666);
		memset(msg.mtext,0,sizeof(msg.mtext));
		msg.types = 10;
		char *a = "0123456789";
		
		for(i=0;i<11;i++)
		{
			strcpy(msg.mtext,a);
			sleep(1);
			msgsnd(msgqid,&msg,sizeof(msg.mtext),0);
			printf("(Client) send datatype %ld : %s\n",msg.types,msg.mtext);
			msg.types--;
			a++;
			if(msg.types == 0)
			{
				sleep(1);
				printf("Client shutdown\n");
				exit(0);
			}
		}
	}
	else
	{
		pid_t server;
		server = fork();
		if(server < 0)
		{
			perror("fork");
		}
		if(server == 0)
		{
			int msgqid;
			int i;
			MSG msg;
			msgqid = msgget(75,IPC_CREAT|0666);
			
			msg.types = 10;
			while(msg.types != 0)
			{
				sleep(1);
				msgrcv(msgqid,&msg,sizeof(msg.mtext),msg.types,0);
				printf("\t\t\t\t(Server) recv datatype %ld : %s\n",msg.types,msg.mtext);
				msg.types--;
			}
			msgctl(msgqid,IPC_RMID,NULL);
			sleep(1);
			printf("Sever type 1 shutdown\n");
			msgctl(msgqid,IPC_RMID,NULL);
			exit(0);
			
		}
		else
		{
			wait(NULL);
			sleep(1);
			printf("father process quit\n");	
		}
	}
}