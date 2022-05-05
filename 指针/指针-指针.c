#include <stdio.h>
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",&arr[9] - arr[0]);//9——中间的元素个数
	return 0;
}


//模拟strlen
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while(end != '\0')
	{
		end++;
	}
	return end - start;
}


int main()
{
	char arr[] = "bit";
	//int len = strlen(arr;);   //求字符串长度
	//printf("%d\n",len);

	//模拟实现一个strlen函数
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len = %d\n",len);
	return 0;
}