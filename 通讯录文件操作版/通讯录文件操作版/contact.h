# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)

//这里来声明函数
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
//# define MAX 1000
# define DEFAULT_CAPACITY 3    //初始的容量设置为3
# define NAME_MAX 20
# define SEX_MAX 10
# define TEL_MAX 20
# define ADDR_MAX 20

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;
typedef struct Contact
{
	struct PeoInfo* data;
	int size;
	int capacity;
	//struct PeoInfo data[MAX]; //结构体数组，最大能容纳1000个联系人信息
	//int size;  //表示已经存入的信息有多少
}Contact;




//初始化通讯录
void Initcontact( Contact*);
//增加联系人
void Add(Contact* ps);
//打印通讯录
void Show(const Contact* ps);
//删除指定联系人
void Del(Contact* ps);
//修改联系人信息
void Modify(Contact* ps);
//查找联系人信息
void Search(const Contact* ps);
//按姓名排列
void Sort(Contact* ps);
//释放空间
void Destory(Contact* ps);
//保存联系人信息到文件中
void Save(Contact* ps);
