# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//int main()
//{
//	int i = 0;   //���i��arr����λ�þͲ�����ѭ���ˣ���Ϊ��ʹ�øߵ�ַ��i�Ǵ����arr����ģ�Խ����ʲ����ܷ��ʵ�i
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		printf("haha\n");
//		arr[i] = 0;    //����Խ�����   arr[12]�ĵ�ַ��i�ĵ�ַ����ͬ��
//						//���Իᵼ�³�����ѭ��  ��arr[12]���൱�ڸ���i
//	}
//	system("pause");
//	return 0;
//}


//ģ��ʵ�ֿ⺯��strcpy

//void my_strcpy(char* p1, char* p2)
//{
//	while (*(p1 - 1) != '\0' && *(p2 - 1) != '\0')
//	{
//		*(p1++) = *(p2++);
//	}
//}

// �Ż�һ��
//void my_strcpy(char* p1, char* p2)
//{
//	while (*(p1++) = *(p2++))  //  ��������\0��ʱ����ѭ��
//	{
//	    ;
//	}
//}


// ���Ż�һ��  ����assert����
# include <assert.h>
//void my_strcpy(char* p1, char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	while (*(p1++) = *(p2++)) 
//	{
//		;
//	}
//}

// �����Ż�һ��  ����assert����  ��const���α���  ������������Ϊchar*
# include <assert.h>
char* my_strcpy(char* p1, const char* p2)  // const �����α�ʾԭ�ַ��������޸�
{
	char* ret = p1;
	assert(p1 != NULL);
	assert(p2 != NULL);
	while (*(p1++) = *(p2++))
	{
		;
	}
	return ret;
}


int main()
{
	char arr1[] = "#######";
	char arr2[] = "hello";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}




int my_strlen(const char* str)
{
	int count = 0;
	assert(str != NULL);         //����assert��const���Ӵ��뽡׳��
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}