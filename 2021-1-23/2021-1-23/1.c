# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>

//  模拟计算器
void menu()
{
	printf("**************************\n");
	printf("***1.add          2.sub***\n");
	printf("***3.mul          4.div***\n");
	printf("*******   0.exit   *******\n");
}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择》：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出程序");
//			break;
//		default :
//			printf("选择错误，请重选\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//  函数指针的应用，对上面函数做改变
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择》：");
//		scanf("%d", &input);
//		int (*Parr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			int ret = Parr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else
//		{
//			printf("选择错误，请重新选择\n");
//		}
//	} while (input);
//	return 0;
//}


// 利用回调解决冗余代码问题，相似的那一坨再封装成函数

//void caol(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数：");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择》：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			caol(Add);
//			//printf("请输入两个操作数：");
//			//scanf("%d%d", &x, &y);
//			//printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			caol(Sub);
//			break;
//		case 3:
//			caol(Mul);
//			break;
//		case 4:
//			caol(Div);
//			break;
//		case 0:
//			printf("退出程序");
//			break;
//		default:
//			printf("选择错误，请重选\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

# include <stdlib.h>
# include <string.h>
//qsort函数尝试 qsort(数组起始地址，数组长度，元素大小，compare函数）
//qsort使用的是快速排序
//int cmp_int(const void* x, const void* y)
//{
//	return (*(int*)x - *(int*)y);  //强制类型转化再解引用
//}
//
//int main()
//{
//	int arr[5] = { 2,1,5,3,4 };
//	qsort(arr, 5, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

// qsort排浮点型的数组
//int cmp_f(const void* x, const void* y)
//{
//	return (int)(*(int*)x - *(int*)y);  //强制类型转化再解引用
//}
//
//
//int main()
//{
//	float f[5] = { 0.02,0.23,0.01,0.3,4.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_f);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//	return 0;
//}

//qsort 排结构体类型的

struct stu
{
	char name[20];
	int age;
};
//  按年龄排序
int cmp_stu_by_age(const void* x, const void* y)
{
	return ((struct stu*)x)->age - ((struct stu*)y)->age;
}

void test()
{
	struct stu s[3] = { {"zhangsan",30}, {"lisi",20}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}

//  按名字首字母排序
int cmp_stu_by_name(const void* x, const void* y)
{
	// 字符串的比较不能直接加减，需要用strcmp函数
	// strcmp使用方法是按两个字符串的ASCII码值，从左到右依次比较，第一个相同再比较下一个
	// 否则直接返回第一个字符减去第二个字符的ASCII码值，如果第一个的ASCII的小，返回负值  eg：abc的ASCII小于bcd的ASCII，返回负值
	return strcmp( ((struct stu*)x)->name , ((struct stu*)y)->name);  
}

void test2()
{
	struct stu s[3] = { {"zhangsan",30}, {"lisi",20}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);  // 如果最后一个返回的是负值就把第一个排在前面，说明前面的小

}	

int main()
{
	//test();
	test2();
	return 0;
}





