#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

typedef struct _msg
{
	long mtype;
	char mtext[50];
}MSG;

int main(int argc, char *argv[])
{
	key_t key;
	int msgqid;
	MSG msg;

	key = ftok(".",2022);
	msgqid = msgget(key, IPC_CREAT|0666);
	if(msgqid == -1)
	{
		perror("msgget");
		exit(-1);
	}
	msg.mtype = 25;
	strcpy(msg.mtext, "hehe");
	msgsnd(msgqid, &msg, sizeof(msg.mtext),0);
	return 0;
}
