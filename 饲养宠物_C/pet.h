#pragma once
struct Pet
{
	unsigned int select_pet;
	unsigned int age;	//当前年龄
	unsigned int Max_age;//最大生命值
	//char name[30];//名字
	int hungery;//饥饿值
	int thirsty;//口渴值
	int mood;//心情值
	int step;//行到点数
	int time;//早、中、晚的值
	int healthy;//健康值
};

void init_func(struct Pet *p);
void print_tuzi();
void print_ma();
void print_niu();