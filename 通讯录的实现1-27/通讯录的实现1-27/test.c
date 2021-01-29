# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include "contact.h"
//这里测试

//1.存放1000个好友信息
//名字
//电话
//性别
//住址
//年龄
//2.增加好友信息
//3.删除指点姓名的好友信息
//4.查找好友信息
//5.修改好友信息
//6.打印好友信息
//7.排序
void menu()
{
	printf("***************************************\n");
	printf("*******1.add            2.del   *******\n");
	printf("*******3.search         4.modify*******\n");
	printf("*******5.show           6.sort  *******\n");
	printf("************   0.tuichu   ***************\n");
	printf("***************************************\n");
}

//用枚举增加代码可读性
enum option
{
	tuichu,
	add,
	del,
	search,
	modify,
	show,
	sort,
};

int main()
{
	int input = 0;
	//在头文件中用结构体创建通讯录
	struct Contact con;   //con就是通讯录，包含1000个信息空间，和已经存入的个数
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择：》");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Add(&con);
			break;
		case del:
			Del(&con);
			break;
		case search:
			Search(&con);
			break;
		case modify:
			Modify(&con);
			break;
		case show:
			Show(&con);
			break;
		case sort:
			Sort(&con);
			break;
		case tuichu:
			printf("即将退出");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}