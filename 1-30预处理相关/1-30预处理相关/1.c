# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include <stdio.h>

//int main()
//{
//	printf("%s", __TIME__);
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	FILE* pf = fopen("log.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "file:%s line:%d time:%s date:%s i:%d\n",
//			__FILE__, __LINE__, __TIME__, __DATE__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		fprintf(stdout, "file:%s line:%d time:%s date:%s i:%d\n",
			__FILE__, __LINE__, __TIME__, __DATE__, i);
	}
	return 0;
}