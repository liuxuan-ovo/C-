#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>

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