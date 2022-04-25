#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sockfd = 0;
	char buf[1024] = "";
	unsigned short port = 8000;
	struct sockaddr_in send_addr;

	
	bzero(&send_addr,sizeof(send_addr));
	send_addr.sin_family = AF_INET;
	send_addr.sin_port = htons(port);
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	if(sockfd < 0)
	{
		perror("socket error");
		exit(1);
	}
	if(argc > 1)
	{
		send_addr.sin_addr.s_addr = inet_addr(argv[1]);
	}
	else
	{
		printf("not have a server IP\n");
		exit(1);
	}
	int yes = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&yes,sizeof(yes));
	
	stpcpy(buf,"boardcast sucess");
	int len = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr *)&send_addr,sizeof(send_addr));
	
	if(len < 0)
	{
		printf("send error\n");
		close(sockfd);
		exit(1);
	}
	return 0;
}