#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main()
{
	int sockfd=0;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("socket");
		exit(-1);
	}
	int err_log = 0;
	struct sockaddr_in my_addr;
	unsigned short port = 8000;
	bzero(&my_addr,sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	err_log = bind(sockfd, (struct sockaddr *)&my_addr,sizeof(my_addr));
	if(err_log != 0)
		{
			perror("binding");
			close(sockfd);
			exit(-1);
		}
	err_log = listen(sockfd,10);
	if(err_log != 0)
	{
		perror("listen");
		close(sockfd);
		exit(-1);
	}
	struct sockaddr_in client_addr;
	char recv_buf[512] = """";
	char cli_ip[INET_ADDRSTRLEN] = """";
	socklen_t client_addr_len = sizeof(client_addr);

	int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
	if(connfd < 0)
	{
		perror("accept");
		close(sockfd);
		exit(-1);
	}
	inet_ntop(AF_INET, &client_addr.sin_addr,cli_ip,INET_ADDRSTRLEN);
	printf("cli_ip:%s, port = %d\n",cli_ip,ntohs(client_addr.sin_port));

	read(connfd,recv_buf,sizeof(recv_buf));
}