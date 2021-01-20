# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>

void init(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}



void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//  实现数组的逆置
void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int temp = 0;
	while (left < right)
	{
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	/*init(arr,sz);*/
	reverse(arr, sz);
	print(arr, sz);
	return 0;
}

交换数组
void Swap(int arr1[], int sz1, int arr2[], int sz2)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < sz1; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}



int main()
{
	int arr1[5] = { 1,1,1,1,1 };
	int arr2[5] = { 2,2,2,2,2 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	Swap(arr1,sz1, arr2,sz2);
	print(arr1, sz1);
	printf("\n");
	print(arr2, sz2);
	return 0;
}

  计算一个数的二进制中1的个数
int Count_bit_one(int n)
{
	int count = 0;
	for (count = 0; n ; count++)
	{
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int count = Count_bit_one(n);
	printf("count=%d\n", count);
	return 0;
}

	  求两个数的二进制位不相同的个数
int main()
{
		int x = 0;
		int y = 0;
		int count = 0;
		scanf("%d%d", &x, &y);
		int n = x ^ y;
		count=Count_bit_one(n);
		printf("%d\n", count);
}

 打印一个数的二进制奇数位和偶数位

void print(int n)
{
	int i = 0;
	printf("奇数位：\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("偶数位：\n");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	print(n);
	return 0;
}

  打印n*n乘法口诀表

void print_table(n)
{
	int i = 1;
	int j = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d ",j,i, j * i);
		}
		printf("\n");
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	print_table(n);
	return 0;
}
# include <string.h>
void reverse_string(char*arr, int left, int right)
{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		if ((left+1) < (right-1))   //  不然会多交换一次
		{
			reverse_string(arr, left+1, right-1);
		}
}

void reverse_string2(char* arr)
{
	int i = 0;
	int sz = strlen(arr);
	char tmp = arr[i];
	arr[i] = arr[sz - 1];
	arr[sz - 1] = '\0';
	if (strlen(arr + 1) >= 2)
		reverse_string2(arr + 1);
	arr[sz - 1] = tmp;
}


int main()
{
	char arr[] = "abcdef";
	int sz = strlen(arr);
	reverse_string2(arr);
	printf("%s", arr);
	return 0;
}


//  递归实现求一个数的每位之和
int DightSum(unsigned int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return n % 10 + DightSum(n / 10);
	}
}
int main()
{
	unsigned int n = 0;
	scanf("%d", &n);
	int sum=DightSum(n);
	printf("%d", sum);
	return 0;
}



// 递归实现一个数的k次方
double Kpower(int num, int k)
{
	if (k < 0)
		return (1.0 / Kpower(num, -k));
	if (k == 0)
		return 1;
	else
	{
		return num * Kpower(num, k-1);
	}
}


int main()
{
	int num = 0;
	int k = 0;
	scanf("%d%d", &num, &k);
	double ret = Kpower(num, k);
	printf("ret=%lf\n", ret);
	return 0;
}