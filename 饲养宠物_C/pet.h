#pragma once
struct Pet
{
	unsigned int select_pet;
	unsigned int age;	//��ǰ����
	unsigned int Max_age;//�������ֵ
	//char name[30];//����
	int hungery;//����ֵ
	int thirsty;//�ڿ�ֵ
	int mood;//����ֵ
	int step;//�е�����
	int time;//�硢�С����ֵ
	int healthy;//����ֵ
};

void init_func(struct Pet *p);
void print_tuzi();
void print_ma();
void print_niu();