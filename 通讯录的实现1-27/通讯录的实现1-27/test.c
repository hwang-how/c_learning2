# define _CRT_SECURE_NO_WARNINGS 1
# pragma warning(disable:6031)
# include "contact.h"
//�������

//1.���1000��������Ϣ
//����
//�绰
//�Ա�
//סַ
//����
//2.���Ӻ�����Ϣ
//3.ɾ��ָ�������ĺ�����Ϣ
//4.���Һ�����Ϣ
//5.�޸ĺ�����Ϣ
//6.��ӡ������Ϣ
//7.����
void menu()
{
	printf("***************************************\n");
	printf("*******1.add            2.del   *******\n");
	printf("*******3.search         4.modify*******\n");
	printf("*******5.show           6.sort  *******\n");
	printf("************   0.tuichu   ***************\n");
	printf("***************************************\n");
}

//��ö�����Ӵ���ɶ���
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
	//��ͷ�ļ����ýṹ�崴��ͨѶ¼
	struct Contact con;   //con����ͨѶ¼������1000����Ϣ�ռ䣬���Ѿ�����ĸ���
	Initcontact(&con);
	do
	{
		menu();
		printf("��ѡ�񣺡�");
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
			printf("�����˳�");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}