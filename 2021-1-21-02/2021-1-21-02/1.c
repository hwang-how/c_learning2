# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
// �жϵ�ǰ�����Ǵ�˻���С��

int check()
{
	int a = 1;
	return *(char*)&a;
}

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;   // ǿ������ת����char*
//	//if (*p == 1)
//	//	printf("��С��\n");
//	//else
//	//	printf("�Ǵ��\n");
//	return 0;
//}
   // ��ò�Ҫ���Զ��庯���ڲ���ӡ   �ú�������һЩֵ��������



int main()
{
	int ret = check();
	// �������1��ʾС��  ����0��ʾ���
	if (ret == 1)
		printf("��С��\n");
	else
		printf("�Ǵ��\n");
	return 0;
}