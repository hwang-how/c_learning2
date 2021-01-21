# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//int main()
//{
//	int i = 0;   //如果i和arr换个位置就不会死循环了，因为先使用高地址，i是存放在arr下面的，越界访问不可能访问到i
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		printf("haha\n");
//		arr[i] = 0;    //出现越界访问   arr[12]的地址和i的地址是相同的
//						//所以会导致出现死循环  改arr[12]就相当于改了i
//	}
//	system("pause");
//	return 0;
//}


//模拟实现库函数strcpy

//void my_strcpy(char* p1, char* p2)
//{
//	while (*(p1 - 1) != '\0' && *(p2 - 1) != '\0')
//	{
//		*(p1++) = *(p2++);
//	}
//}

// 优化一下
//void my_strcpy(char* p1, char* p2)
//{
//	while (*(p1++) = *(p2++))  //  拷贝到‘\0’时结束循环
//	{
//	    ;
//	}
//}


// 再优化一下  断言assert函数
# include <assert.h>
//void my_strcpy(char* p1, char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	while (*(p1++) = *(p2++)) 
//	{
//		;
//	}
//}

// 再再优化一下  断言assert函数  加const修饰变量  返回类型设置为char*
# include <assert.h>
char* my_strcpy(char* p1, const char* p2)  // const 来修饰表示原字符串不可修改
{
	char* ret = p1;
	assert(p1 != NULL);
	assert(p2 != NULL);
	while (*(p1++) = *(p2++))
	{
		;
	}
	return ret;
}


int main()
{
	char arr1[] = "#######";
	char arr2[] = "hello";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}




int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);         //增加assert和const增加代码健壮性
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}