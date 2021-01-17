# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"

void Initboard(char board[ROW][COL],int row, int col)   //�����Ķ����װ�����β�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

//  ��ӡ����
void Displayboard(char board[ROW][COL], int row, int col)
{
	//�����
	//int i = 0;
	//for (i = 0; i < ROW; i++)
	//{
	//	printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	//	if (i<ROW-1)
 //          printf("---|---|---\n");
	//}
	//�޸İ�   �ڲ�����forѭ��
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			//��ӡ������
			printf(" %c ", board[i][j]);
			if (j<COL-1)
			   printf("|");
		}
		printf("\n");
		    //��ӡ�ָ��� 
		if (i < ROW - 1)
		{

			for (j = 0; j < COL; j++)
				{
					printf("---");
					if (j < COL - 1)
						printf("|");
				}
				printf("\n");
		}
	}

}

// �������
void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���������\n");
	while (1)
	{
		printf("���������꡷:");
		scanf("%d%d", &x, &y);
		// �������
		//if (board[x-1][y-1] != ' ')
		//{
		//	printf("�����걻ռ�ã�����������\n");
		//}
		//else if (x > row || y > col)
		//{
		//	printf("����Ƿ�������������\n");
		//}
		//else
		//{
		//	board[x - 1][y - 1] = '*';
		//	break;
		//}

		// �ж�����ֵ�ĺϷ���
		if (x <= row&&y <= col&&x >= 1 && y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ�ã�����������\n");
		}
		else
			printf("����Ƿ�������������\n");
	}

}

 //��������
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		/*srand((unsigned int)time(NULL));*/  //  !!! ��������ֻ����һ��
		x = rand()%row;                   //  Ī����������srand              
	    y = rand()%col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}


}

int Isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

  //  �ж�˭Ӯ����
  //   ����'*'���ʤ  '#������ʤ 'C'������Ϸ  'Q' ����
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	// �ж�����������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1]&&board[i][1] == board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
			break;
		}
	}
	// �ж�����������
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j]&&board[1][j] == board[2][j]&&board[0][j]!=' ')
		{
			return board[0][j];
			break;
		}
	}
	// �ж����Խ�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	// �жϸ��Խ���
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == Isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}
