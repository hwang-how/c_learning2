# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <string.h>
# include <errno.h>
// ͨ�����������ļ�����д����
//int main()
//{
//	FILE* pfwrite = fopen("test.txt", "w"); //�����ڵ�ǰ·������ᴴ��һ���ļ�
//	if (pfwrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//д�ļ�
//		fputc('n', pfwrite);
//		fputc('i', pfwrite);
//		fputc('h', pfwrite);
//		fputc('a', pfwrite);
//		fputc('o', pfwrite);
//		fclose(pfwrite);
//		pfwrite = NULL;
//	}
//	return 0;
//}

// ����Ͳ���д�뵽�ļ���ȥ�ˣ�ֱ��д�뵽��׼����豸����Ļ����
//int main()
//{
//	fputc('h', stdout);
//	fputc('h', stdout);
//	fputc('h', stdout);
//	fputc('h', stdout);
//	fputc('h', stdout);
//	fputc('h', stdout);
//	fputc('h', stdout);
//	return 0;
//}

//fgetc ��ʹ��
//int main()
//{
//	//�Ӽ����������������ȡ
//	int ch1 = fgetc(stdin);
//	printf("%c", ch1);
//	return 0;
//}

//���ļ���������ȡ
//int main()
//{
//	FILE* pfread = fopen("test.txt", "r");
//	if (pfread == NULL)
//	{
//		return 0;
//	}
//	int ch1 = fgetc(pfread);
//	printf("%c", ch1);
//	//�ر��ļ�
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}


//fgets����һ�ζ�ȡ����ַ�����ʹ��
//���ļ����������
//int main()
//{
//	FILE* pfread = fopen("test.txt", "r");
//	if (pfread == NULL)
//	{
//		return 0;
//	}
//	char bufer[1024] = { 0 };
//	fgets(bufer,1024,pfread);
//	printf("%s\n", bufer);
//	//�ر��ļ�
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}

// ���������ٴ�ӡ
//int main()
//{
//	char bufer[1024] = { 0 };
//	fgets(bufer, 1024, stdin);
//	printf("%s\n", bufer);
//	return 0;
//}

//fputs������ʹ��
//��fputsд�뵽�ļ���
//int main()
//{
//	FILE* pfwrite = fopen("test.txt", "w");
//	if (pfwrite == NULL)
//	{
//		return 0;
//	}
//	fputs("hello\n", pfwrite);
//	fclose(pfwrite);
//	pfwrite = NULL;
//	return 0;
//}
//�������Ļ��
//int main()
//{
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	fputs("hello\n", stdout);
//	return 0;
//}

//fread ��fwrite��ʹ��
struct S
{
	char name[20];
	int age;
	double score;
};
//fread ��ʹ��
//int main()
//{
//	struct S s = { "����",20,90.2 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fwrite(&s, sizeof(struct S), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//fwrite ��ʹ��
int main()
{
	//struct S s = { "����",20,90.2 };
	struct S tmp = { 0 };
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		return 0;
	}
	fread(&tmp, sizeof(struct S), 1, pf);
	printf("%s %d %lf", tmp.name, tmp.age, tmp.score);
	fclose(pf);
	pf = NULL;
	return 0;
}