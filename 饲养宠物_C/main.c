#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pet.h"
#include "func.h"



int main(){
	struct Pet pet;

	printf("��ѡ����Ҫ�����ڳ��\n");
	printf("1������ 2��ţ 3���� \n");
	printf("������ѡ��");
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
	//printf("�Ƿ�鿴����˵��\n");

	system("pause");
	return 0;
}