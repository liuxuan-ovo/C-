#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#define BUFSZ 2048
int main(int argc,char *argv[])
{
	pid_t client;
	client = fork();
	if(client < 0)
	{
		perror("fork error\n");
	}
	if(client == 0)
	{
		int shmid;
		long type = 10;
		int i;
		char *a = "abcdefghig";
		char *shmadd;
		shmid = shmget(75,BUFSZ,SHM_R|SHM_W|IPC_CREAT);
		if(shmid < 0)
		{
			perror("shmget");
			exit(-1);
		}
		shmadd = shmat(shmid,NULL,0);
		bzero(shmadd,BUFSZ);
		for(i = 0;i < 11;i++)
		{
			sleep(1);
			bzero(shmadd,BUFSZ);
			strcpy(shmadd,a);
			printf("(Client) sent type %ld :%s\n",type,shmadd);
			type--;
			a++;
			if(type == 0)
			{
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
			perror("fork error\n");
        }
		if(server == 0)
		{
			int shmid;
			long type = 10;
			char *shmadd;
			shmid = shmget(75,BUFSZ,SHM_R|SHM_W);
			shmadd = shmat(shmid,NULL,0);
			bzero(shmadd,BUFSZ);
			while(type != 0)
			{
				sleep(1);
				printf("\t\t\t\t(Server) recv type %ld :%s\n",type,shmadd);
				type--;
				
			}
			
			printf("Sever type 1 shutdown\n");
			shmdt(shmadd);
			shmctl(shmid,IPC_RMID,NULL);
			
		}
		else
		{
			wait(NULL);
			sleep(1);
			printf("Process quit\n");
		}
	}
}