#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sockfd = 0;
	int error_log = 0;
	struct sockaddr_in bind_addr;
	unsigned short port = 8000;
	
	if(argc > 1)
	{
		port = atoi(argv[1]);
	}
	printf("UDP Server Started!\n");
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket error");
		exit(-1);
	}
	bzero(&bind_addr,sizeof(bind_addr));
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_port = htons(port);
	bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	printf("Binding server to port %d\n",port);
	error_log = bind(sockfd,(struct sockaddr*)&bind_addr,sizeof(bind_addr));
	if(error_log != 0)
	{
		perror("bind error");
		close(sockfd);
		exit(-1);
	}
	printf("Waiting data from other client...\n");
	while(1)
	{
		char recv_buf[1024] = "";
		char cli_ip[INET_ADDRSTRLEN] = "";
		int recv_len = 0;
		struct sockaddr_in client_addr;
		socklen_t client_addr_len = sizeof(client_addr);
		
		recv_len = recvfrom(sockfd,recv_buf,sizeof(recv_buf),0,(struct sockaddr*)&client_addr,&client_addr_len);
		inet_ntop(AF_INET,&client_addr.sin_addr,cli_ip,INET_ADDRSTRLEN);
		printf("client ip = %s\n",cli_ip);
		
		sendto(sockfd,recv_buf,recv_len,0,(struct sockaddr*)&client_addr,client_addr_len);
	}
	close(sockfd);
	return 0;
}