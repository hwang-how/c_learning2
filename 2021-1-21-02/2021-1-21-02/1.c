# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
// 判断当前机器是大端还是小端

int check()
{
	int a = 1;
	return *(char*)&a;
}

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;   // 强制类型转化成char*
//	//if (*p == 1)
//	//	printf("是小端\n");
//	//else
//	//	printf("是大端\n");
//	return 0;
//}
   // 最好不要在自定义函数内部打印   让函数返回一些值告诉我们



int main()
{
	int ret = check();
	// 如果返回1表示小端  返回0表示大端
	if (ret == 1)
		printf("是小端\n");
	else
		printf("是大端\n");
	return 0;
}