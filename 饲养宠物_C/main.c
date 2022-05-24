#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pet.h"
#include "func.h"



int main(){
	struct Pet pet;

	printf("请选择您要领养在宠物：\n");
	printf("1、兔子 2、牛 3、马 \n");
	printf("请输入选择：");
	scanf("%d",&pet.select_pet);
	switch (pet.select_pet)
	{
		case 1:
			print_tuzi();
			break;
		case 2:
			print_niu();
			break;
		case 3:
			print_ma();
			break;
		default:
			break;
	}
	init_func(&pet);
	raise(&pet);
	//printf("是否查看饲养说明\n");

	system("pause");
	return 0;
}