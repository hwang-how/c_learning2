# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include<stdio.h>
# include<string.h>
# include<assert.h>
// ������
//A˵������
//B˵��C
//C˵��D
//D˵c�ں�˵
//��������˵���滰��1����˵�ļٻ�

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

//��ת�ַ���
//���� ABCD����һ���ַ����ǰ���ߵ��õ��ұߣ����BCDA
//ʵ��һ��������������ת�ַ�����k���ַ�

//����1�����������
void Rotate(char arr[], int k, int sz)
{
	int i = 0;
	for (i = 0; i < k; i++)//������ת����
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
//	printf("���������ת���ַ�����");
//	scanf("%s", arr);
//	int sz = strlen(arr); 
//	printf("������Ҫ��ת���ַ�����");
//	scanf("%d", &k);
//	Rotate(arr, k,sz);
//	printf("��ת����ַ���Ϊ��%s", arr);
//	return 0;
//}

//����2��������ת�� ��������
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
//	printf("���������ת���ַ�����");
//	scanf("%s", arr);
//	int sz = strlen(arr);
//	printf("������Ҫ��ת���ַ�����");
//	scanf("%d", &k);
//	if (k < sz)
//	{
//		Reverse(arr, 0, k - 1);
//		Reverse(arr, k, sz - 1);
//		Reverse(arr, 0, sz - 1);
//		printf("��ת����ַ���Ϊ��%s", arr);
//	}
//	else
//		printf("�������");
//	return 0;
//}

//�ж�arr2�ַ����ǲ���arr1��ת������
//��1 ��ٷ�
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
//		printf("��\n");
//	else
//		printf("��\n");
//	return 0;
//}

//��2����arr1׷��һ���Լ������abcdefabcdef���ж�arr2�ǲ���arr1���Ӵ�
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
	strncat(arr1, arr1,len1);  //�Լ����Լ�׷�ӵ�ʱ�������������
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
//		printf("��\n");
//	else
//		printf("��\n");
//	return 0;
//}


//���Ͼ����в���һ������Ҫ��ʱ�临�Ӷ�С��O��n��

//int Findnum(int arr[3][3], int row, int col, int k)
//{
//	int x = 0;
//	int y = col-1;  //�ҵ����Ͻǵ�Ԫ��
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
//	int k = 17;//����7
//	int ret = Findnum(arr, 3, 3, k);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//	}
//	else
//	{
//		printf("δ�ҵ�\n");
//	}
//	return 0;
//}


//  ����Ҫ�ҵ���Ҫ��ӡ�±꣬���Ҳ����ڲ��Һ�����������ӡ
//  ��������к��д�ַ�������ڵ��õĺ��������޸�
int Findnum(int arr[3][3], int* row, int* col, int k)
{
	int x = 0;
	int y = *col - 1;  //�ҵ����Ͻǵ�Ԫ��
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
	int k = 7;//����7
	int row = 3;
	int col = 3;
	int ret = Findnum(arr, &row, &col, k);  //�����Ƿ����͵ĺ���
	if (ret == 1)
	{
		printf("�ҵ���,�±��ǣ�%d %d\n",row,col);
	}
	else
	{
		printf("δ�ҵ�\n");
	}
	return 0;
}