# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <string.h>
# include <assert.h>

//1.strlen()
//�����ַ�������ʵ��
//�ݹ�ʵ��
int my_strlen(char* str)
{
	if (*str == 0)
	{
		return 0;
	}
	else
		return 1 + my_strlen(str + 1);
}
//int main()
//{
//	int len = my_strlen("abcdefgh");
//	printf("%d", len);
//	return 0;
//}

//ʵ��strstr()
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	else
//	{
//		char* p1 = (char*)str1;
//		char* p2 = (char*)str2;
//		int i = 0;
//		while (i <= (int)(strlen(str1) - strlen(str2)))
//		//while(*p1)
//		{
//			p1 = (char*)str1+i;
//			p2 = (char*)str2;
//			while (*p1  && *p2  && *p1++ == *p2++)
//			{
//				;
//			} 
//			if (*p2 == '\0')
//			{
//				 return (char*)str1+i;   //�����ַ����ȷ���Ӵ�����ʼ��ַû��
//			}
//			i++; 
//			//p1++;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	char* str1 = "ab";
//	char* str2 = "def";
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("δ�ҵ��Ӵ�");
//	}
//	else
//	{
//		printf("�ҵ��Ӵ�:%s",ret);
//	}
//	return 0;
//}

# include<ctype.h>
//int main()
//{
//	char arr[] = "I AM A STUDENT";
//	int i = 0;
//	while (arr[i])
//	{
//		arr[i] = tolower(arr[i]);
//		i++;
//	}
//	printf("%s", arr);
//	return 0;
//}

//ģ��ʵ��memcpy
//void my_memcpy(void* dest, const void* src, int num)
//{
//	char* p1 = (char*)dest;
//	char* p2 = (char*)src;//ʵ�ֵ����ֽڵĿ�����ת����char*����
//	int i = 0;
//	while (i < num)
//	{
//		*(p1 + i) = *(p2 + i);
//		i++;
//	}
//	return dest;
//}
//
//void my_memcpy2(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//	}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	my_memcpy2(arr2, arr1, sizeof(arr1));
//	return 0;
//}

//ģ��ʵ��memmove
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret= dest;
	if (dest>src)   //�Ƚϴ�С��ʱ����Բ�������
	{
		//��ʱ���н�����dest��src�󣬲��ô�src���濪ʼ��ǰ����
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
			
	}
	else
	{
	    //Ŀ�ĵ���Դ��ַǰ�����н���
	    //�������ֱ��Դ��ַ��ǰ��󿽱�����
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	return dest;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(arr+2, arr, 20);
	int i = 0;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
