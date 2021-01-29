# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)

//��������������
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
//# define MAX 1000
# define DEFAULT_CAPACITY 3    //��ʼ����������Ϊ3
# define NAME_MAX 20
# define SEX_MAX 10
# define TEL_MAX 20
# define ADDR_MAX 20

struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
};
struct Contact
{
	struct PeoInfo* data;
	int size;
	int capacity;
	//struct PeoInfo data[MAX]; //�ṹ�����飬���������1000����ϵ����Ϣ
	//int size;  //��ʾ�Ѿ��������Ϣ�ж���
};




//��ʼ��ͨѶ¼
void Initcontact(struct Contact*);
//������ϵ��
void Add(struct Contact* ps);
//��ӡͨѶ¼
void Show(const struct Contact* ps);
//ɾ��ָ����ϵ��
void Del(struct Contact* ps);
//�޸���ϵ����Ϣ
void Modify(struct Contact* ps);
//������ϵ����Ϣ
void Search(const struct Contact* ps);
//����������
void Sort(struct Contact* ps);
//�ͷſռ�
void Destory(struct Contact* ps);