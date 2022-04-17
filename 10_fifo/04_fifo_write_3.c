#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd;
	char send[100] = "hello I love you";

	fd = open("my_fifo",O_WRONLY|O_NONBLOCK);
	if(fd<0)
	{
		printf("fd=%d\n",fd);
		perror("open fifo");
	}
	write(fd,send,strlen(send));
	printf("write to my_fifo buf=%s\n",send);
	while(1);
	return 0;
}
