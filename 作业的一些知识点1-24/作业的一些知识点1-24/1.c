# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <assert.h>
# include <string.h>

//指针减去指针得到的是指针间的元素个数
//
//
//
//
//
//
//
//
//
// 逆置字符串的内容
//void Reverse(char arr[])
//{
//	char* str = arr;
//	char* end = arr;
//	while (*(end+1))
//	{
//		end++;
//	}
//	while (str < end)
//	{
//		char tmp = *str;
//		*str = *end;
//		*end = tmp;
//		str++;
//		end--;
//	}
//}
// 修改版
void Reverse(char* str)
{
	assert(str);
	char* left = str;
	int len = strlen(str);
	char* right = str+len-1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

//int main()
//{
//	char arr[343] = { 0 };
//	//scanf("%s", arr);
//	// 可以用gets函数来读取一行  scanf碰到空格就不再读取
//	gets(arr);
//	Reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//求 sum=a+aa+aaa+aaaa+aaaaa的值
//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d%d", &a, &n);
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}

// 打印1-100000之间的水仙花数 例如153 1的三次方加5的三次方加3的三次方=153
# include <math.h>
int Judge(int i)
{
	int tmp = i;
	//求出该数的次数(位数)
	int pownum = 0;
	while (i)
	{
		pownum++;
		i /= 10;
	}
	int sum = 0;
	i = tmp;
	while (i)
	{
		sum += pow(i%10,pownum);
		i /= 10;
	}
	if (sum == tmp)
		return 1;
	else
		return 0;

}
//int main()
//{
//	int i = 1;
//	for (i = 1; i <= 100000; i++)
//	{
//		int ret=Judge(i);
//		if (ret == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



// 打印菱形
int main()
{
	int line = 0;   //这里的行数为上半部分的行数
	scanf("%d", &line);
	//打印上半部分
	int i = 0;
	for (i = 0; i < line; i++)
	{
		//打印空格  上半部分是七行的话第一行打印六个空格
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*号，第一行打印一个，二行三个，三行五个
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < line - 1; i++)
	{
		//打印空格，下部分六行，第一行一个空格，11个*
		int j = 0;
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}