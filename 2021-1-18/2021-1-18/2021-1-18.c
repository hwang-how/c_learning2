# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>

//int main()
//{
//	int a = -1;
//	int b = a >> 1;
//	printf("%d\n", b);
//	return 0;
//}


  //������������λ1�ĸ���
//��1
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
	printf("������1��λ��Ϊ��%d\n", count);
	return 0;
}

// ��2
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
	printf("������1��λ��Ϊ��%d\n", count);
	return 0;
}