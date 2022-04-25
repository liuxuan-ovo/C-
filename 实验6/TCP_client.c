#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd = 0;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	int err_log = 0;
	unsigned short port = 8000;           //服务器端口号
	char *server_ip = "192.168.146.128";  //服务器ip地址
	struct sockaddr_in server_addr;       //不通用的套接字
	
	bzero(&server_addr,sizeof(server_addr));//初始化服务器地址
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_pton(AF_INET, server_ip,&server_addr.sin_addr);
	
	//主动连接服务器
	err_log = connect(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr));
	if(err_log != 0)
	{
		perror("connect");
		close(sockfd);
		exit(-1);
	}
	//通信
	while(1)
	{
		char send_buf[512] = "Hello! Welcome here!\r\n";
		char recv_buf[512] = "Hello! Welcome here!\r\n";
		
		fgets(send_buf,sizeof(send_buf),stdin);
		send_buf[strlen(send_buf)-1] = '\0';
		
		write(sockfd,send_buf,strlen(send_buf));
		read(sockfd,recv_buf,sizeof(recv_buf));
		printf("%s\n",recv_buf);
	}
	close(sockfd);
	return 0;
}
