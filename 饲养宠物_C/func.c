#include "func.h"

void raise(struct Pet *p){
	char next;
	int w = 0;
	int emg = 0;
	unsigned int choice = 0;
	fflush(stdin);
	while(1){
		w = rand()%5;//����
		if(p->time == 1){
			printf("����������\n");
		}else if(p->time == 2){
			printf("����������\n");
			
		}else if(p->time == 3){
			printf("����������\n");
		}
		if(w == 0){printf("��������\n");}
		else if(w == 1){printf("��������\n");}
		else if(w == 2){printf("������С��\n");}
		else if(w == 3){printf("����������\n");}
		else if(w == 4){printf("���������\n");}
		printf("======================\n");
		printf("��ѡ�����ڲ�����1��ιʳ 2��ιˮ 3������ 4����ˣ 5�������κ���\n");
		printf("�����룺");
		scanf("%d",&choice);
		switch (choice){	
			case 1:
				p->hungery--;
				p->step = p->step - 5;  break;
			case 2:
				p->thirsty--;
				p->step = p->step - 3;  break;
			case 3:
				if (w == 0){p->mood = p->mood + 2;}
				else if (w == 1){p->mood++;}
				else if (w == 2){p->mood++;}
				else if (w == 3){
					p->mood--;
					p->thirsty--;
				}
				else if (w == 4){
					p->mood--;
					p->hungery--;
				}
				p->step = p->step - 3;  break;
			case 4:
				if (w == 0){p->mood = p->mood + 2;}
				else if (w == 1){p->mood++;}
				else if (w == 2){
					p->hungery++;
					p->thirsty++;
					p->healthy++;
				}
				else if (w == 3){
					p->hungery = p->hungery + 2;
					p->thirsty++;
					p->healthy++;
				}
				else if (w == 4){
					p->hungery++;
					p->thirsty++;
					p->healthy++;
				}
				p->step = p->step - 8;  break;
			case 5:
				break;
			default:
				break;
		}
		printf("======================\n");
		
		p->time++;
		p->step += 5;

		printf("����ֵ��%d\n",p->hungery);
		printf("�ڿ�ֵ��%d\n",p->thirsty);
		printf("�ж�������%d\n",p->step);
		printf("���飺%d\n",p->mood);
		printf("����ֵ��%d\n",p->healthy);

		if(p->time > 3)	{
			p->time = 1;
			p->age++;
		}
		if (p->step <= 0){
			printf("��Ϸ���� Gime over\n");break;
		}
		if(p->age > p->Max_age) break;
		emg = rand()%21;
		if (emg == 20){
			p->healthy--;
			p->step = p->step - 10;
			printf("������\n");
		}
		else if (p->healthy < 0){
			printf("������\n");
			printf("��������\n");break;
		}
		else if (p->hungery > 6||p->thirsty > 5){
			printf("��������\n");
			printf("��������\n");break;
		}
		else if (p->hungery > 5&&p->thirsty > 4){
			printf("�������������\n");
			printf("��������\n");break;
		}
		else if (p->hungery == 3){
			p->mood--;
			printf("����\n");
		}
		else if (p->hungery == -2){
			p->mood--;
			printf("�ܱ���\n");
		}

		else if (p->hungery > 3){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("Ҫ������\n");
		}
		else if (p->hungery < -2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("Ҫ������\n");
		}
		else if (p->thirsty == 2){
			p->mood--;
			printf("�ÿ�\n");
		}
		else if (p->thirsty == -2){
			p->mood--;
			printf("�ȹ���\n");
		}
		else if (p->thirsty > 2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("�ʵ��ܲ���\n");
		}
		else if (p->thirsty < -2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("�ȳ���\n");
		}
	}
		if (p->age > p->Max_age){
		printf("happy end ��������\n");
		}

}