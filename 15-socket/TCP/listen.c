err_log = listen(sockfd,10);
if(err_log != 0)
{
	perror("listen");
	close(sockfd);
	exit(-1);
}