#include<sys/socket.h>
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