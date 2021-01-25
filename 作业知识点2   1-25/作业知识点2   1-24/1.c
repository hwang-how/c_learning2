# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include<stdio.h>
//知识点
//const int*p和int const *p等价  const都在*的左边
//大小端字节序是指的数据在电脑中存储的字节顺序而不是二进制位的顺序
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

// 喝汽水问题，一瓶汽水一元，两个空瓶换一瓶，20元可以喝几瓶
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
//将一个数组的奇数全部放在前面，偶数放在后面
void move(int arr[], int sz)
{
	int i = 0;
	int j = sz-1;
	while (i < j)
	{
		while (i < j && arr[i] % 2)   //这里也应该补充上条件才合适
		{                             //不然全是奇数或者偶数的时候会发生越界
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
//	c = a + b;  //这里会发生整形提升，是按32位进行计算的
//	            //但是c又只能存8个比特位
//	printf("%d %d", a + b, c);
//	            // 要以%d的形式打印又要发生整形提升，a+b直接打印结果
//	            // c发生整形提升再打印
//	return 0;
//}

// 打印杨辉三角
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
	//先把第一列和对角线的变成1
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