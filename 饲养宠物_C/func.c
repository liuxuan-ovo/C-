#include "func.h"

void raise(struct Pet *p){
	char next;
	int w = 0;
	int emg = 0;
	unsigned int choice = 0;
	fflush(stdin);
	while(1){
		w = rand()%5;//天气
		if(p->time == 1){
			printf("现在是上午\n");
		}else if(p->time == 2){
			printf("现在是下午\n");
			
		}else if(p->time == 3){
			printf("现在是晚上\n");
		}
		if(w == 0){printf("天气：晴\n");}
		else if(w == 1){printf("天气：阴\n");}
		else if(w == 2){printf("天气：小雨\n");}
		else if(w == 3){printf("天气：暴风\n");}
		else if(w == 4){printf("天气：大风\n");}
		printf("======================\n");
		printf("请选择您在操作：1、喂食 2、喂水 3、抚摸 4、玩耍 5、不做任何事\n");
		printf("请输入：");
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

		printf("饥饿值：%d\n",p->hungery);
		printf("口渴值：%d\n",p->thirsty);
		printf("行动点数：%d\n",p->step);
		printf("心情：%d\n",p->mood);
		printf("健康值：%d\n",p->healthy);

		if(p->time > 3)	{
			p->time = 1;
			p->age++;
		}
		if (p->step <= 0){
			printf("游戏结束 Gime over\n");break;
		}
		if(p->age > p->Max_age) break;
		emg = rand()%21;
		if (emg == 20){
			p->healthy--;
			p->step = p->step - 10;
			printf("生病了\n");
		}
		else if (p->healthy < 0){
			printf("倒下了\n");
			printf("宠物死亡\n");break;
		}
		else if (p->hungery > 6||p->thirsty > 5){
			printf("万恶的主人\n");
			printf("宠物死亡\n");break;
		}
		else if (p->hungery > 5&&p->thirsty > 4){
			printf("来世不跟你混了\n");
			printf("宠物死亡\n");break;
		}
		else if (p->hungery == 3){
			p->mood--;
			printf("饿了\n");
		}
		else if (p->hungery == -2){
			p->mood--;
			printf("很饱了\n");
		}

		else if (p->hungery > 3){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("要饿死了\n");
		}
		else if (p->hungery < -2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("要撑死了\n");
		}
		else if (p->thirsty == 2){
			p->mood--;
			printf("好渴\n");
		}
		else if (p->thirsty == -2){
			p->mood--;
			printf("喝够了\n");
		}
		else if (p->thirsty > 2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("渴得受不了\n");
		}
		else if (p->thirsty < -2){
			p->mood = p->mood - 2;
			p->healthy--;
			printf("喝撑了\n");
		}
	}
		if (p->age > p->Max_age){
		printf("happy end 寿终正寝\n");
		}

}