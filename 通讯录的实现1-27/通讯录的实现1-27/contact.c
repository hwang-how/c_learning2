# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include "contact.h"
//������ʵ�ֺ�������
void Initcontact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;  //�ʼû�д�����ϵ�� 0��
}
void Add(struct Contact* ps)
{
	if (ps->size == 1000)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("�������½���ϵ��������");
		scanf("%s", ps->data[ps->size].name);
		printf("�������½���ϵ�����䣺");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������½���ϵ���Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("�������½���ϵ�˵绰��");
		scanf("%s", ps->data[ps->size].tel);
		printf("�������½���ϵ��סַ��");
		scanf("%s", ps->data[ps->size].addr);
	}
	ps->size++;
	printf("��ӳɹ�!\n");
}

void Show(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
//static ���δ˺�������ʱ�������ֻ��������ļ�������
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
//�㷨˼�룺�ҵ���Ԫ�أ��Ӻ���ǰ���ǣ�Ȼ�󳤶ȼ����Ϳ���ʵ����
{
	if (ps->size == 0)
	{
		printf("��ǰ��ϵ���б�Ϊ��\n");
	}
	else
	{
		char name[NAME_MAX] = { 0 };
		printf("������Ҫɾ������ϵ������:>");
		scanf("%s", name);
		int pos = FindByName(ps, name);
		if (pos == ps->size)
		{
			printf("δ�ҵ�����ϵ�ˣ�������ȷ�ϣ�\n");
		}
		else
		{
			while (pos < ps->size - 1)
			{
				ps->data[pos] = ps->data[pos+1];
				pos++;
			}
			ps->size--;
			printf("ɾ���ɹ���\n");
		}

	}
}
void Modify(struct Contact* ps)
{
	printf("������Ҫ�޸ĵ���ϵ������:>");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("δ�ҵ�����ϵ��\n");
	}
	else
	{
		printf("����ϵ����ϢΪ��\n");
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-10s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tel,
			ps->data[pos].addr);
		printf("�������޸ĵ���Ϣ:\n");
		printf("����:");
		scanf("%s", ps->data[pos].name);
		printf("����:");
		scanf("%d", &ps->data[pos].age);
		printf("�Ա�:");
		scanf("%s", ps->data[pos].sex);
		printf("�绰:");
		scanf("%s", ps->data[pos].tel);
		printf("סַ:");
		scanf("%s", ps->data[pos].addr);
	}
	printf("�޸ĳɹ���\n");
}

void Search(const struct Contact* ps)
{
	printf("������Ҫ���ҵ���ϵ������:>");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (strcmp(ps->data[i].name, name) == 0)   //����Ĳ��ҹ��̺�ɾ������Ĳ��ҹ�����ͬ�����ִ����������⣬���Է�װ�ɺ������
	//	{
	//		break;
	//	}
	//}
	//�˲��Һ����ҵ������±꣬δ�ҵ�����-1��
	int pos=FindByName(ps, name);
	if ( pos== -1)
	{
		printf("δ�ҵ�����ϵ��\n");
	}
	else
	{
		printf("����ϵ����ϢΪ��\n");
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-10s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tel,
			ps->data[pos].addr);
	}
}

//  ����������ĸ����

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