# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include<stdio.h>
//֪ʶ��
//const int*p��int const *p�ȼ�  const����*�����
//��С���ֽ�����ָ�������ڵ����д洢���ֽ�˳������Ƕ�����λ��˳��
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

// ����ˮ���⣬һƿ��ˮһԪ��������ƿ��һƿ��20Ԫ���Ժȼ�ƿ
//int main()
//{
//	int mey = 0;
//	scanf("%d", &mey);
//	int sum = mey;
//	int empty = mey;
//	while (empty>1)
//	{
//		sum += empty / 2;
//		empty=empty/2+empty%2;
//	}
//	printf("%d", sum);
//	return 0;
//}
//��һ�����������ȫ������ǰ�棬ż�����ں���
void move(int arr[], int sz)
{
	int i = 0;
	int j = sz-1;
	while (i < j)
	{
		while (i < j && arr[i] % 2)   //����ҲӦ�ò����������ź���
		{                             //��Ȼȫ����������ż����ʱ��ᷢ��Խ��
			i++;
		}
		while (i < j && arr[j] % 2!=1)
		{
			j--;
		}
		if (i < j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;  //����ᷢ�������������ǰ�32λ���м����
//	            //����c��ֻ�ܴ�8������λ
//	printf("%d %d", a + b, c);
//	            // Ҫ��%d����ʽ��ӡ��Ҫ��������������a+bֱ�Ӵ�ӡ���
//	            // c�������������ٴ�ӡ
//	return 0;
//}

// ��ӡ�������
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10.........
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	//�Ȱѵ�һ�кͶԽ��ߵı��1
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i > 1 && j >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-5d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}