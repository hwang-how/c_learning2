# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"

void Initboard(char board[ROW][COL],int row, int col)   //函数的定义封装，定形参
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

//  打印棋盘
void Displayboard(char board[ROW][COL], int row, int col)
{
	//低配版
	//int i = 0;
	//for (i = 0; i < ROW; i++)
	//{
	//	printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
	//	if (i<ROW-1)
 //          printf("---|---|---\n");
	//}
	//修改版   内部两个for循环
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			//打印数据行
			printf(" %c ", board[i][j]);
			if (j<COL-1)
			   printf("|");
		}
		printf("\n");
		    //打印分隔行 
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

// 玩家下棋
void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请玩家下棋\n");
	while (1)
	{
		printf("请输入坐标》:");
		scanf("%d%d", &x, &y);
		// 有问题的
		//if (board[x-1][y-1] != ' ')
		//{
		//	printf("该坐标被占用，请重新输入\n");
		//}
		//else if (x > row || y > col)
		//{
		//	printf("坐标非法，请重新输入\n");
		//}
		//else
		//{
		//	board[x - 1][y - 1] = '*';
		//	break;
		//}

		// 判断输入值的合法性
		if (x <= row&&y <= col&&x >= 1 && y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}

}

 //电脑下棋
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下\n");
	while (1)
	{
		int x = 0;
		int y = 0;
		/*srand((unsigned int)time(NULL));*/  //  !!! 整个函数只调用一次
		x = rand()%row;                   //  莫法在这里用srand              
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

  //  判断谁赢函数
  //   返回'*'玩家胜  '#’电脑胜 'C'继续游戏  'Q' 和棋
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	// 判断有无行三连
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1]&&board[i][1] == board[i][2]&&board[i][0]!=' ')
		{
			return board[i][0];
			break;
		}
	}
	// 判断有无列三连
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j]&&board[1][j] == board[2][j]&&board[0][j]!=' ')
		{
			return board[0][j];
			break;
		}
	}
	// 判断主对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	// 判断副对角线
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == Isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}
