# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>

//int main()
//{
//	int a = -1;
//	int b = a >> 1;
//	printf("%d\n", b);
//	return 0;
//}


  //求整数二进制位1的个数
//法1
int main()
{
	int num = 0;
	int count = 0;
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num = num / 2;
	}
	printf("二进制1的位数为：%d\n", count);
	return 0;
}

// 法2
int main()
{
	int num = 0;
	int count = 0;
	int i = 0;
	scanf("%d", &num);
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
			count++;
	}
	printf("二进制1的位数为：%d\n", count);
	return 0;
}