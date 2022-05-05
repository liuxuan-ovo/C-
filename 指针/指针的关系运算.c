//两种写法第一种更好，符合C语言标准规定
#define N_VALUES 5
float values[N_VALUES];
float *vp;
//指针+-整数：指针的关系运算
for(vp = &values[N_VALUES]; vp > &values[0]; )
{
	*--vp = 0;;
}

//代码改造
for(vp = &values[N_VALUES - 1]; vp > &values[0]; vp--)
{
	*vp = 0;;
}
