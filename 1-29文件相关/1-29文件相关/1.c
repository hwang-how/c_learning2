# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>
# include <string.h>
# include <errno.h>
// 通过代码来往文件里面写东西
//int main()
//{
//	FILE* pfwrite = fopen("test.txt", "w"); //这里在当前路径下面会创建一个文件
//	if (pfwrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//写文件
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

// 这里就不是写入到文件中去了，直接写入到标准输出设备（屏幕）上
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

//fgetc 的使用
//int main()
//{
//	//从键盘输入的内容来读取
//	int ch1 = fgetc(stdin);
//	printf("%c", ch1);
//	return 0;
//}

//从文件里面来读取
//int main()
//{
//	FILE* pfread = fopen("test.txt", "r");
//	if (pfread == NULL)
//	{
//		return 0;
//	}
//	int ch1 = fgetc(pfread);
//	printf("%c", ch1);
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}


//fgets（能一次读取多个字符）的使用
//从文件里面读出来
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
//	//关闭文件
//	fclose(pfread);
//	pfread = NULL;
//	return 0;
//}

// 键盘输入再打印
//int main()
//{
//	char bufer[1024] = { 0 };
//	fgets(bufer, 1024, stdin);
//	printf("%s\n", bufer);
//	return 0;
//}

//fputs函数的使用
//用fputs写入到文件中
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
//输出到屏幕上
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

//fread 和fwrite的使用
struct S
{
	char name[20];
	int age;
	double score;
};
//fread 的使用
//int main()
//{
//	struct S s = { "张三",20,90.2 };
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
//fwrite 的使用
int main()
{
	//struct S s = { "张三",20,90.2 };
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