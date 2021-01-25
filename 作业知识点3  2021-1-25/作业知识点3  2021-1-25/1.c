# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include<stdio.h>
# include<string.h>
# include<assert.h>
// 猜凶手
//A说不是我
//B说是C
//C说是D
//D说c在胡说
//有三个人说了真话，1个人说的假话

//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer:%c", killer);
//		}
//	}
//	return 0;
//}

//旋转字符串
//比如 ABCD左旋一个字符串是把左边的拿到右边，变成BCDA
//实现一个函数，可以旋转字符串的k个字符

//方法1，暴力解决法
void Rotate(char arr[], int k, int sz)
{
	int i = 0;
	for (i = 0; i < k; i++)//控制旋转几个
	{
		char tmp = arr[0];
		int j = 0;
		for (j = 0; j < sz - 1; j++)  
		{
			arr[j] = arr[j + 1];
		}
		arr[j] = tmp;
	}
}
//int main()
//{
//	char arr[100] = { 0 };
//	int k = 0;
//	printf("请输入待旋转的字符串：");
//	scanf("%s", arr);
//	int sz = strlen(arr); 
//	printf("请输入要旋转的字符数：");
//	scanf("%d", &k);
//	Rotate(arr, k,sz);
//	printf("旋转后的字符串为：%s", arr);
//	return 0;
//}

//方法2，三部翻转法 三个逆序
Reverse(char* arr, int left, int right)
{
	assert(arr);
	while (left < right)
	{
		char tmp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = tmp;
		left++;
		right--;
	}
}
//int main()
//{
//	char arr[100] = { 0 };
//	int k = 0;
//	printf("请输入待旋转的字符串：");
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	printf("请输入要旋转的字符数：");
//	scanf("%d", &k);
//	if (k < sz)
//	{
//		Reverse(arr, 0, k - 1);
//		Reverse(arr, k, sz - 1);
//		Reverse(arr, 0, sz - 1);
//		printf("旋转后的字符串为：%s", arr);
//	}
//	else
//		printf("输入错误");
//	return 0;
//}

//判断arr2字符串是不是arr1旋转得来的
//法1 穷举法
int is_rotate(char* arr1, char* arr2)
{
	assert(arr1);
	assert(arr2);
	int len1 = strlen(arr1);
	int k = 0;
	for (k = 0; k < len1; k++)
	{
		//while ((*arr1 == *arr2) && *arr1 != 0 && *arr2 != 0)
		//{
		//	arr1++;
		//	arr2++;
		//}
		//if ((*arr1 == *arr2) && *arr1 == 0 && *arr2 == 0)
		//{
		//	return 1;
		//}
		int ret = strcmp(arr1, arr2);
		if (ret == 0)
		{
			return 1;
		}
		else
		{
			char tmp = arr1[0];
			int j = 0;
			for (j = 0; j < len1 - 1; j++)
			{
				arr1[j] = arr1[j + 1];
			}
			arr1[j] = tmp;
			
		}
	}
	return 0;
}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret=is_rotate(arr1, arr2);
//	if (ret == 1)
//		printf("是\n");
//	else
//		printf("否\n");
//	return 0;
//}

//法2，把arr1追加一个自己，变成abcdefabcdef，判断arr2是不是arr1的子串
int is_rotate2(char* arr1, char* arr2)
{
	assert(arr1);
	assert(arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(arr1, arr1,len1);  //自己给自己追加的时候不能用这个函数
	//int i = 0;
	//int k = 0;
	//for (i = 0; i < len; i++)
	//{
	//	int j = 0;
	//	while (arr1[j + i] = arr2[j] && j < len)
	//	{
	//		j++;
	//	}
	//	if (j == len)
	//	{
	//		return 1;
	//	}
	//}
	char* ret=strstr(arr1, arr2);
	if (ret != NULL)
		return 1;
	else
		return 0;
}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "defab";
//	int ret = is_rotate2(arr1, arr2);
//	if (ret == 1)
//		printf("是\n");
//	else
//		printf("否\n");
//	return 0;
//}


//杨氏矩阵中查找一个数，要求时间复杂度小于O（n）

//int Findnum(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col-1;  //找到右上角的元素
//	while (x <= 2 && y >= 0)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 17;//查找7
//	int ret = Findnum(arr, 3, 3, k);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("未找到\n");
//	}
//	return 0;
//}


//  不仅要找到还要打印下标，并且不能在查找函数里面来打印
//  这里采用行和列传址，才能在调用的函数里面修改
int Findnum(int arr[3][3], int* row, int* col, int k)
{
	int x = 0;
	int y = *col - 1;  //找到右上角的元素
	while (x <= *row-1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*row = x;
			*col = y;
			return 1;
		}
	}
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;//查找7
	int row = 3;
	int col = 3;
	int ret = Findnum(arr, &row, &col, k);  //这里是返回型的函数
	if (ret == 1)
	{
		printf("找到了,下标是：%d %d\n",row,col);
	}
	else
	{
		printf("未找到\n");
	}
	return 0;
}