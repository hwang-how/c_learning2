# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <assert.h>
# include <string.h>

//ָ���ȥָ��õ�����ָ����Ԫ�ظ���
//
//
//
//
//
//
//
//
//
// �����ַ���������
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
// �޸İ�
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
//	// ������gets��������ȡһ��  scanf�����ո�Ͳ��ٶ�ȡ
//	gets(arr);
//	Reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//�� sum=a+aa+aaa+aaaa+aaaaa��ֵ
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

// ��ӡ1-100000֮���ˮ�ɻ��� ����153 1�����η���5�����η���3�����η�=153
# include <math.h>
int Judge(int i)
{
	int tmp = i;
	//��������Ĵ���(λ��)
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



// ��ӡ����
int main()
{
	int line = 0;   //���������Ϊ�ϰ벿�ֵ�����
	scanf("%d", &line);
	//��ӡ�ϰ벿��
	int i = 0;
	for (i = 0; i < line; i++)
	{
		//��ӡ�ո�  �ϰ벿�������еĻ���һ�д�ӡ�����ո�
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*�ţ���һ�д�ӡһ���������������������
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++)
	{
		//��ӡ�ո��²������У���һ��һ���ո�11��*
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