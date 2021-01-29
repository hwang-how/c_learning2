# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include "contact.h"
//这里来实现函数功能
void Initcontact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;  //最开始没有存入联系人 0个
}
void Add(struct Contact* ps)
{
	if (ps->size == 1000)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入新建联系人姓名：");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入新建联系人年龄：");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入新建联系人性别：");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入新建联系人电话：");
		scanf("%s", ps->data[ps->size].tel);
		printf("请输入新建联系人住址：");
		scanf("%s", ps->data[ps->size].addr);
	}
	ps->size++;
	printf("添加成功!\n");
}

void Show(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "姓名", "年龄", "性别", "电话", "住址");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-5d\t%-5s\t%-12s\t%-10s\n",
				ps->data[i].name, 
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tel,
				ps->data[i].addr);
		}
	}

}
//static 修饰此函数，此时这个函数只能在这个文件里面用
static int FindByName(const struct Contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Del(struct Contact* ps)
//算法思想：找到该元素，从后向前覆盖，然后长度减减就可以实现了
{
	if (ps->size == 0)
	{
		printf("当前联系人列表为空\n");
	}
	else
	{
		char name[NAME_MAX] = { 0 };
		printf("请输入要删除的联系人姓名:>");
		scanf("%s", name);
		int pos = FindByName(ps, name);
		if (pos == ps->size)
		{
			printf("未找到该联系人，请重新确认！\n");
		}
		else
		{
			while (pos < ps->size - 1)
			{
				ps->data[pos] = ps->data[pos+1];
				pos++;
			}
			ps->size--;
			printf("删除成功！\n");
		}

	}
}
void Modify(struct Contact* ps)
{
	printf("请输入要修改的联系人姓名:>");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("未找到该联系人\n");
	}
	else
	{
		printf("该联系人信息为：\n");
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-10s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tel,
			ps->data[pos].addr);
		printf("请输入修改的信息:\n");
		printf("姓名:");
		scanf("%s", ps->data[pos].name);
		printf("年龄:");
		scanf("%d", &ps->data[pos].age);
		printf("性别:");
		scanf("%s", ps->data[pos].sex);
		printf("电话:");
		scanf("%s", ps->data[pos].tel);
		printf("住址:");
		scanf("%s", ps->data[pos].addr);
	}
	printf("修改成功！\n");
}

void Search(const struct Contact* ps)
{
	printf("请输入要查找的联系人姓名:>");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (strcmp(ps->data[i].name, name) == 0)   //这里的查找过程和删除里面的查找过程相同，出现代码冗余问题，可以封装成函数解决
	//	{
	//		break;
	//	}
	//}
	//此查找函数找到返回下标，未找到返回-1；
	int pos=FindByName(ps, name);
	if ( pos== -1)
	{
		printf("未找到该联系人\n");
	}
	else
	{
		printf("该联系人信息为：\n");
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-10s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tel,
			ps->data[pos].addr);
	}
}

//  按名字首字母排序

//void Sort(struct Contact* ps)
//{
//	int i = 0;
//	int width = sizeof(ps->data[0]);
//	for (i = 0; i < ps->size; i++)
//	{
//		if (strcmp(ps->data[i].name, ps->data[i + 1].name) > 0)
//		{
//			int j = 0;
//			for (j = 0; j < width; j++)
//			{
//				char tmp = 0;
//				tmp = *((char*)(ps->data+i) + j);
//				*((char*)(ps->data + i) + j) = *((char*)(ps->data + i+1) + j);
//				*((char*)(ps->data + i + 1) + j) = tmp;
//			}
//		
//		}
//	}
//}
int cmp_by_name(const void* x, const void* y)
{
	return strcmp(((struct PeoInfo*)x)->name ,((struct PeoInfo*)y)->name);
}
void Sort(struct Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_by_name);
}