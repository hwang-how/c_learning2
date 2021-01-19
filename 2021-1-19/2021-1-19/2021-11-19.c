# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>


int main()
{
	int arr[10] = { 0 };
	int* p = arr;  //p指向首地址
	/*char* p = arr;  */  //这个是错的
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


int main()
{
	int a[10] = { 0 };
	int* p = a;
	int i = 0;
	for (i = 0; i <= 12; i++)
	{
		*p = i;
		p++;
	}
	return 0;
}


  求字符串的长度   利用指针减去指针
int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start; 
}
int main()
{
	char arr[] = "hello";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}


int main()
{
	int a = 1;
	int* p = &a;
	int** pp = &p;
	**pp = 20;
	printf("%d\n", *p);
	printf("%d", **pp);
	return 0;
}



//  指针数组
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int* arr[] = { &a,&b,&c,&d };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(arr[i]));
	}
	return 0;
}