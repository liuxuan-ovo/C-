#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

#define BUFSZ 2048

int main(int argc, char *argv[])
{
	int shmid;
	int ret;
	key_t key;
	char *shmadd;

	key = ftok(".",2012);
	if(key == -1)
	{
		perror("ftok");
	}
	system("ipcs -m");
	
	shmid = shmget(key, BUFSZ, SHM_R|SHM_W);
	if(shmid < 0)
	{
		perror("shmget");
		exit(-1);
	}

	shmadd = shmat(shmid, NULL, 0);
	if(shmadd < 0)
	{
		perror("shmat");
		exit(-1);
	}
	printf("copy data from shared-memory\n");
	printf("data = [%s]\n",shmadd);
	
	ret = shmdt(shmadd);
	if(ret < 0)
	{
		perror("shmdt");
		exit(1);
	}	
	else
	{
		printf("delete shared-memory\n");
	}
	shmctl(shmid, IPC_RMID, NULL);
	system("ipcs -m");
	return 0;
}
