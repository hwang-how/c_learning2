# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <string.h>
# include <assert.h>

//1.strlen()
//有三种方法可以实现
//递归实现
int my_strlen(char* str)
{
	if (*str == 0)
	{
		return 0;
	}
	else
		return 1 + my_strlen(str + 1);
}
//int main()
//{
//	int len = my_strlen("abcdefgh");
//	printf("%d", len);
//	return 0;
//}

//实现strstr()
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	else
//	{
//		char* p1 = (char*)str1;
//		char* p2 = (char*)str2;
//		int i = 0;
//		while (i <= (int)(strlen(str1) - strlen(str2)))
//		//while(*p1)
//		{
//			p1 = (char*)str1+i;
//			p2 = (char*)str2;
//			while (*p1  && *p2  && *p1++ == *p2++)
//			{
//				;
//			} 
//			if (*p2 == '\0')
//			{
//				 return (char*)str1+i;   //这个地址不正确，子串的起始地址没存
//			}
//			i++; 
//			//p1++;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char* str1 = "ab";
//	char* str2 = "def";
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("未找到子串");
//	}
//	else
//	{
//		printf("找到子串:%s",ret);
//	}
//	return 0;
//}

# include<ctype.h>
//int main()
//{
//	char arr[] = "I AM A STUDENT";
//	int i = 0;
//	while (arr[i])
//	{
//		arr[i] = tolower(arr[i]);
//		i++;
//	}
//	printf("%s", arr);
//	return 0;
//}

//模拟实现memcpy
//void my_memcpy(void* dest, const void* src, int num)
//{
//	char* p1 = (char*)dest;
//	char* p2 = (char*)src;//实现单个字节的拷贝，转化成char*类型
//	int i = 0;
//	while (i < num)
//	{
//		*(p1 + i) = *(p2 + i);
//		i++;
//	}
//	return dest;
//}
//
//void my_memcpy2(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	my_memcpy2(arr2, arr1, sizeof(arr1));
//	return 0;
//}

//模拟实现memmove
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret= dest;
	if (dest>src)   //比较大小的时候可以不用类型
	{
		//此时会有交汇且dest比src大，采用从src后面开始向前拷贝
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
			
	}
	else
	{
	    //目的地在源地址前面且有交汇
	    //这种情况直接源地址从前向后拷贝就行
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	return dest;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(arr+2, arr, 20);
	int i = 0;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
