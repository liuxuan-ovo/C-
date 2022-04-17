
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd1;
	int fd2;
	//0 1 2
	fd2=dup(1);//save stdout
	// 0 1 2 3
	printf("new:fd2=%d\n",fd2);//3
	
	fd1=open("test",O_CREAT|O_RDWR, S_IRWXU);//4
	//0 1 2 3 4
	close(1);
	//0   2 3 4
	dup(fd1);//1---> test
	//0 1 2 3 4
	printf("hello world\n");
	
	close(1);
	//0   2 3 4
	dup(fd2);//reset 1--->stdout 
	//0 1 2 3 40
	printf("i love you \n");
	return 0;
}





