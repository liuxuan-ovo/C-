#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem_g, sem_p;
int i=0,j=0,product=0;
//char ch = 'a';

void *pthread_g(void *arg)
{
	while(product>0)
	{
		sem_wait(&sem_g);//-1
		printf("消费者消费了第%d个产品\n",product);
		product--;
		printf("the product num is %d\n",product);
		sleep(1);
		sem_post(&sem_p);//+1
	}
printf("product num is 0\n");
}

void *pthread_p(void *arg)
{
	while(product<11)
	{
		sem_wait(&sem_p);//-1
		product++;3
		printf("生产者生产了%d个产品\n",product);
		//fflush(stdout);
		sem_post(&sem_g);//+1
	}
	printf("the product is full\n");
	sleep(3);
}

int main(void)
{
	pthread_t tid1, tid2;

	sem_init(&sem_g, 0, 0);
	sem_init(&sem_p, 0, 1);

	pthread_create(&tid1, NULL, pthread_g, NULL);
	pthread_create(&tid2, NULL, pthread_p, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
