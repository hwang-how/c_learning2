# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>

//  ģ�������
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
//		printf("��ѡ�񡷣�");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�����");
//			break;
//		default :
//			printf("ѡ���������ѡ\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//  ����ָ���Ӧ�ã������溯�����ı�
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("��ѡ�񡷣�");
//		scanf("%d", &input);
//		int (*Parr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//		if (input >= 1 && input <= 4)
//		{
//			printf("������������������");
//			scanf("%d%d", &x, &y);
//			int ret = Parr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����\n");
//		}
//		else
//		{
//			printf("ѡ�����������ѡ��\n");
//		}
//	} while (input);
//	return 0;
//}


// ���ûص��������������⣬���Ƶ���һ���ٷ�װ�ɺ���

//void caol(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("������������������");
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
//		printf("��ѡ�񡷣�");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			caol(Add);
//			//printf("������������������");
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
//			printf("�˳�����");
//			break;
//		default:
//			printf("ѡ���������ѡ\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

# include <stdlib.h>
# include <string.h>
//qsort�������� qsort(������ʼ��ַ�����鳤�ȣ�Ԫ�ش�С��compare������
//qsortʹ�õ��ǿ�������
//int cmp_int(const void* x, const void* y)
//{
//	return (*(int*)x - *(int*)y);  //ǿ������ת���ٽ�����
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

// qsort�Ÿ����͵�����
//int cmp_f(const void* x, const void* y)
//{
//	return (int)(*(int*)x - *(int*)y);  //ǿ������ת���ٽ�����
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

//qsort �Žṹ�����͵�

struct stu
{
	char name[20];
	int age;
};
//  ����������
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

//  ����������ĸ����
int cmp_stu_by_name(const void* x, const void* y)
{
	// �ַ����ıȽϲ���ֱ�ӼӼ�����Ҫ��strcmp����
	// strcmpʹ�÷����ǰ������ַ�����ASCII��ֵ�����������αȽϣ���һ����ͬ�ٱȽ���һ��
	// ����ֱ�ӷ��ص�һ���ַ���ȥ�ڶ����ַ���ASCII��ֵ�������һ����ASCII��С�����ظ�ֵ  eg��abc��ASCIIС��bcd��ASCII�����ظ�ֵ
	return strcmp( ((struct stu*)x)->name , ((struct stu*)y)->name);  
}

void test2()
{
	struct stu s[3] = { {"zhangsan",30}, {"lisi",20}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);  // ������һ�����ص��Ǹ�ֵ�Ͱѵ�һ������ǰ�棬˵��ǰ���С

}	

int main()
{
	//test();
	test2();
	return 0;
}





