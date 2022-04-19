#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys.msg.h>
#include<string.h>

typedef struct _msg
{
	long types;
	char mtext[50];
}MSG;

int main(int argc, char *argv[])
{
	key_t key;
	int msgqid;
	MSG msg;
	
	key = ftok(".",2022);
	msgqid = msgget(key,IPC_CREAT|0666);
	if(magqid == -1)
	{
		perror("msgget");
		exit(-1);
	}
	msgrcv(msgqid,&msg,sizeof(msg.mtext),25,0);
	printf("%d\n",msg.types);
	printf("msg.mtext = %s\n",msg.mtext);
	msgctl(msgqid,IPC_RMID,NULL)

	return 0;
}