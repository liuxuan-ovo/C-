#include<stdio.h>
#include<unistd/h>
#include<stdlib.h>
#include<sys/types>
#include<sys/>
int main(int argc,char *argv[])
{
	int fd1;
	int fd2;

	int ww;
	int tt;
	fd2=dup(1);
	printf("new:fd2=%d\n,fd2");

	fd1=open("test",O_CREAT|O_RDWR,S_IRWXU);
	close(1);

	ww=dup(fd1);
	printf("ww=%d\n",ww);
	printf("hello world\n");	
	//close(1);
	tt=dup(fd2);
	printf("tt=%d\n",tt);
	printf("I love you\n")
	return 0;;
}
