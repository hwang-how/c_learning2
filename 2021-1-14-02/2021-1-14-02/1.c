# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <string.h>
# include <math.h>

//�ݹ����n��쳲��������е�ֵ

int Fib(int n)
{
	if (n > 2)
		return Fib(n - 1) + Fib(n - 2);
	else
		return 1;
}
// ����ʵ�ַ�
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;

		                //int i = 1;
		while(n>2)     //�����                 //  while (i<= n-2)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;


}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}




//�ݹ���n�Ľ׳�

int Fac(int n)
{
	if (n > 1)
		return n*Fac(n - 1);
	else
		return 1;
}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}


�ݹ����ַ�������

int lenth(char*str)
{
	int count = 0;
	while (*str != '\0')    //ע��������*str
	{
		count++;
		str++;
	}
	return count;
}

int lenth(char*str)
{
	if (*str != '\0')
	{
		return 1 + lenth(str+1);
	}
	else
		return 0;
}


int main()
{
	char arr[] = "abcdef";
	int len = lenth(arr);
	printf("%d\n", len);    //���鴫������������λ�ĵ�ַ���������Զ��庯��ʱ�β�Ҫ��ָ���͵�
	return 0;
}



//�ݹ��ӡÿλ����
void print(i)
{
	if (i > 9)
	{
		print(i / 10);
	}
	printf("%d  ", i % 10);
}

int main()
{
	unsigned int i = 0;
	scanf("%d", &i);
	print(i);
	return 0;
}         


// ��ʽ����
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));    //printf  �ķ���ֵ���ַ��ĸ���
	return 0;
}







�۰����   ��װ����
int Binary_search(int a[],int n,int sz)     //������β�a������ʵֻ��һ��ָ��
{
	/*int sz = sizeof(a) / sizeof(a[0]);*/   //�����ڵ��õĺ����ڲ��������鳤��!!!!!!
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (n < a[mid])
			right = mid - 1;
		else if (n>a[mid])
			left = mid + 1;
		else
			return mid;
	}
	if (left>right)
       return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &k);
	int i = Binary_search(arr, k,sz);
	if (i>=0)
		printf("�ҵ������������±��ǣ�%d\n", i);
	else
		printf("����ʧ��\n");
	return 0;
}



�Զ��庯��   �ж��Ƿ�������(�ܱ��������Ҳ��ܱ�100������

int is_leap_year(int n)
{
	if (n % 4 == 0 && n % 100 != 0)
		return 1;
	else
		return 0;
}

int main()
{
	int i = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if (is_leap_year (i) == 1)
			printf("%d ", i);
	}
	return 0;
}



�Զ��庯��  �ж��Ƿ�������(�Գ���)
int is_prime(int n)
{
	int j = 0;
	for (j = 2; j <= sqrt(n); j++)
	{
		if (n%j == 0)
			return 0;
	}
		return 1;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount= %d\n", count);
	return 0;
}




 �Զ��庯��  ������������ֵ
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}


���Swap�Ǵ��   ����ָ����
void Swap2(int*a, int*b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int x = 10;
	int y = 20;
	Swap2(&x , &y);  //  ����������ڴ�����   �����ǵ�ַ  ����ȡ��ַ  ��������ָ��
	printf("x=%d y=%d\n", x, y);
	return 0;
}


�Զ��庯��  ���������м�����ֵ
int max(int a, int b)
{
	//if (a < b)
	//	return b;
	//else
	//	return a;
	return (a > b ? a : b);
}
int main()
{
	int z=max(1, 4);
	printf("%d\n", z);
	return 0;
}



memset ����   memory--�ڴ�   set����    �൱���޸��ַ���ǰ�����ַ�
int main()
{
	char str[] = "nishizhu";
	memset(str, 'h', 8);
	puts(str);
	printf("%s", str);
	return 0;
}