#include <stdio.h>
#include <assert.h>
char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest && src);
	char* tmp = dest;
	while (count && (*dest++ = *src++))
		count--;
	if (count)
		while (--count)
			*dest++ = '\0';
	return tmp;
}
int main()
{
	char arr1[10] = "abcdefghi";
	char arr2[] = "hell";
	my_strncat(arr1, arr2, 6);
	printf("%s\n", arr1);
	return 0;
}