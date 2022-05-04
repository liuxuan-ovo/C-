#include<stdio.h>
struct stu
{
	char name[20];
	int age;
	char id[20];
};
int main()
{
	struct stu s1 = {"张三", 20, "2019160010203"};
	struct stu* ps = &s1;
	printf("%s\n",ps->name);
	printf("%d\n",ps->age);
	printf("%s\n",ps->id);
	//结构体指针->成员名
	/*printf("%s\n",(*ps).name);
	printf("%d\n",(*ps).age);
	printf("%s\n",(*ps).id);*/

	/*printf("%s\n",s1.name);
	printf("%d\n",s1.age);
	printf("%s\n",s1.id);*/
	//结构体变量.成员名
	return 0;
}
