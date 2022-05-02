//编写一个函数reverse_string(cahr *string)(递归实现)
//将参数字符串中的字符反向排列
//不能使用C函数库中的字符串操作函数
#include <stdio.h>
int my_strlen(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
//逆序：reverse_string("abcdef");
//a和f的交换
//逆序 reverse_string("bcde");
void reverse_string(char *arr)
{
	char tmp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];//第一步
	arr[len - 1] = '\0';//第二部
	if (my_strlen(arr + 1) >= 2)//第三步————长度不等于0或1
	{
		reverse_string(arr + 1);
	}
	arr[len - 1] = tmp;//第四步

}
int main()
{
	char arr[] = "abcdef";//fedcba
	reverse_string(arr);
	printf("%s\n",arr);
	return 0;
}



//循环方法
#include <stdio.h>
int my_string(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse_string(char arr[])
{
	int left = 0;
	int right = my_string(arr) - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[] = "abcdef";//fedcba
	reverse_string(arr);
	printf("%s\n",arr);
	return 0;
}