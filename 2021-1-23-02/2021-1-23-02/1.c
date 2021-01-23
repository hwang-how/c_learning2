# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>

// �ú����ص��ķ���ʵ�ָ������͵����ݵ�ð������


//����������ʵ��
void Swap(char* buf1, char* buf2, int width)//ֱ����char�����գ��Ȼ����������Ҳ�ǰ��ֽڲ���
{
	int i = 0;
	for (i = 0; i < width; i++)//width������ÿ��Ԫ�صĴ�С��������а��ֽڽ��������۴���ʲô���͵�����Ԫ�أ���ǿ������ת����char*��һ���ֽ�һ���ֽڵĻ�
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//compare ������ʵ��,�⺯������αȽ�����Ԫ�ص�����ֵ��С��Ӧ���ɳ���Ա�ڵ���bubble���Լ�ʵ�֣���Ϊÿ�����͵ıȽϷ�����һ�������Բ��̶ܹ�һ��
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz; i++)//ȷ����������
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//ȷ��ÿ���ż�������
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//������к����ص���ͬʱ����ַ���������ÿ��Ԫ�أ�cmp��������ֵ����0˵����һ�����ڵڶ���
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
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

void test2()
{
	struct stu s[3] = { {"zhangsan",30}, {"lisi",20}, {"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}

// ����ð��������������
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}
int main()
{
	test2();
	return 0;
}