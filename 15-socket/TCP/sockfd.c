#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
	int sockfd=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	 perror("socket");
	 //exit(-1);
}