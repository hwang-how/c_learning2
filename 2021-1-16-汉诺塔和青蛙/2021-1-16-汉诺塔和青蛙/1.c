# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
//青蛙跳台阶
 
int jump(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return jump(n - 1) + jump(n - 2);

}


//  非递归实现
int jump1(int n)
{
	int a = 1;
	int b = 1;
	int c = 2;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		while (n > 1)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
	}
	return c;
}


int main()
{
	int n=0;
	int ret=0;
	scanf("%d", &n);
	ret=jump1(n);
	printf("总的跳法有：%d种\n",ret);
	return 0;
}



// 汉诺塔
//void move(char c1,char c2)
//{
//	printf("%c------>%c\n", c1, c2);
//}
//
//void hanoi(int n, char x, char y, char z)
//{
//	if (n == 1)
//		move(x, z);
//	else
//	{
//    	hanoi(n - 1, x, z, y);
//		move(x, z);
//		hanoi(n - 1, y, x, z);
//	}
//
//}
//
//
//
//int main()
//{
//	int n = 0;
//	printf("please input num :");
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}