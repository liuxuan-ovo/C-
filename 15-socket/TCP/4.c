#include<arpa/inet.h>
#include<sys/socket.h>
struct sockaddr_in client_addr;
int sockfd = 0;

char recv_buf[512] = """";
char cli_ip[INET_ADDRSTRLEN] = """";
int main(int argc,char *argv[]){
sockfd = socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
perror("socket");
exit(-1);
}
socklen_t client_addr_len = sizeof(client_addr);


int connfd = accept(sockfd,(struct sockaddr*)&client_addr,&client_addr_len);
if(connfd<0)
{
	perror("accept");
	close(sockfd);
	exit(-1);
}

inet_ntop(AF_INET, &client_addr.sin_addr,cli_ip,INET_ADDRSTRLEN);
printf("cli_ip:%s,port = %d\n,cli_ip,ntohs()client_addr.sin_port");

read(connfd, recv_buf,sizeof(recv_buf));
}























int err_log = 0;
struct sockaddr_in my_addr;
unsigned short port = 8000;

int sockfd;
struct sockaddr_in client_addr;
char recv_buf[512] = "";
char cli_ip[INET_ADDRSTRLEN] = "";
socklen_t client_addr_len = sizeof(client_addr);


	bzero(&my_addr,sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	err_log = bind(sockfd, (struct sockaddr *)&my_addr,sizeof(my_addr));
	int connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
	if(err_log != 0)
	{
		perror("binding");
		close(sockfd);
		exit(-1);
	}

	if(connfd)
	{
		perror("accept");
		close(sockfd);
		exit(-1);
	}
	inet_ntop(AF_INET, &client_addr.sin_addr,cli_ip,INET_ADDRSTRLEN);
	printf("cli_ip:%s, port = %d\n",cli_ip,ntohs(client_addr.sin_port));

	read(connfd,recv_buf,sizeof(recv_buf));
