/*=============================================================
 �ļ����ƣ�tcp_echo_srv.c
 ����������TCP Echo Server  ѭ������TCP������������,�������յ������ݻط�
 ά����¼��2008-12-25  V1.0
           2011-08-11  v1.1
		   2013-02-19  v1.2
 ʹ�÷���: ./tcp_echo_srv 8001(���� ./tcp_echo_srv)
 telnet�ͻ��˹رշ���: ��һ��: ctrl+]  �ڶ���:quit
===============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>						
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>				

//=============================================================
// �﷨��ʽ��	int main(int argc, char *argv[])
// ʵ�ֹ��ܣ�	������������һ��TCP Echo Server
// ��ڲ�����	���Դ��θı��Լ��Ķ˿ںţ���ɲ�����ʹ��Ĭ��ֵ
// ���ڲ�����	��
//=============================================================

int main(int argc, char *argv[])
{
	char recv_buf[2048] = "";			// ���ջ�����
	int sockfd = 0;						// �׽���
	int connfd = 0;
	int err_log = 0;
	struct sockaddr_in my_addr;		// ��������ַ�ṹ��
	unsigned short port = 8000;			// �����˿�	
	
	if(argc > 1)						// �ɲ������ն˿�
	{
		port = atoi(argv[1]);
	}
	
	printf("TCP Server Started at port %d!\n", port);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);   // ����TCP�׽���
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	bzero(&my_addr, sizeof(my_addr));	     // ��ʼ����������ַ
	my_addr.sin_family = AF_INET;
	my_addr.sin_port   = htons(port);
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	printf("Binding server to port %d\n", port);
	
	err_log = bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr));
	if( err_log != 0)
	{
		perror("binding");
		close(sockfd);		
		exit(-1);
	}
	
	err_log = listen(sockfd, 10);
	if(err_log != 0)
	{
		perror("listen");
		close(sockfd);		
		exit(-1);
	}	
	
	printf("Waiting client...\n");
	
	while(1)
	{
		size_t recv_len = 0;
		struct sockaddr_in client_addr;		   // ���ڱ���ͻ��˵�ַ
		char cli_ip[INET_ADDRSTRLEN] = "";	    // ���ڱ���ͻ���IP��ַ
		socklen_t cliaddr_len = sizeof(client_addr);      // �����ʼ��!!!

		connfd = accept(sockfd, (struct sockaddr*)&client_addr, &cliaddr_len);       // ���һ���Ѿ�����������
		if(connfd < 0)
		{
			perror("accept");
			continue;
		}
		
		inet_ntop(AF_INET, &client_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);
		printf("client ip = %s\n", cli_ip);
		
		while((recv_len  = recv(connfd, recv_buf, sizeof(recv_buf), 0)) > 0)
		{
			send(connfd, recv_buf, recv_len, 0); 
		}
		
		close(connfd);     //�ر��������׽���
		printf("client closed!\n");
	}
	
	close(sockfd);         //�رռ����׽���
	return 0;
}
