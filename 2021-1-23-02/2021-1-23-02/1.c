# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>

// 用函数回调的方法实现各种类型的数据的冒泡排序


//交换函数的实现
void Swap(char* buf1, char* buf2, int width)//直接拿char来接收，等会里面操作的也是按字节操作
{
	int i = 0;
	for (i = 0; i < width; i++)//width是数组每个元素的大小，这里进行按字节交换，无论传入什么类型的两个元素，都强制类型转化成char*，一个字节一个字节的换
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//compare 函数的实现,这函数是如何比较数组元素的两个值大小，应该由程序员在调用bubble是自己实现，因为每种类型的比较方法不一样，所以不能固定一个
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz; i++)//确定排序趟数
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//确定每次排几对数据
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//这里进行函数回调，同时按地址传入数组的每个元素，cmp函数返回值大于0说明第一个大于第二个
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
//  按年龄排序
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

// 测试冒泡排序整形数组
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