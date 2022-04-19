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
	shmid = shmget(key, BUFSZ, SHM_R|SHM_W|IPC_CREAT);
	if(shmid < 0)
	{
		perror("shmget");
		exit(-1);
	}
	shmadd = shmat(shmid, NULL, 0);
	if(shmadd < 0)
	{
		perror("shmat");
		_exit(-1);
	}
	printf("copy data to shared-memory\n");
	bzero(shmadd, BUFSZ);
	strcpy(shmadd, "data in shared memory\n");
	return 0;
}
