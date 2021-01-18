# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 1;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);   //打印列号
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);  //打印行号
		int j = 1;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);  //打印每个数组元素
		}
		printf("\n");
	}

}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;
	count = Leinum;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col,int x, int y)
{
	if (mine[x][y] == '0' && show[x][y] == '*' && x >= 1 && y >= 1 && x <= row && y <= col)
	{
		show[x][y] = get_Leinum(mine, x, y) + '0';
	}
	if (mine[x-1][y-1] == '0' && show[x-1][y-1] == '*' && x-1 >= 1 && y-1 >= 1 && x-1 <= row && y-1 <= col)
	{
		show[x-1][y-1] = get_Leinum(mine, x-1, y-1)+'0';
		if (get_Leinum(mine, x - 1, y - 1) == 0)
		{
			Openboard(mine, show,row,col, x - 1, y - 1);
		}
	}	
	if (mine[x-1][y] == '0' && show[x-1][y] == '*' && x-1 >= 1 && y >= 1 && x-1 <= row && y <= col)
	{
		show[x-1][y] = get_Leinum(mine, x-1, y)+'0';
		if (get_Leinum(mine, x - 1, y) == 0)
		{
			Openboard(mine, show,row,col, x - 1, y);
		}
	}	
	if (mine[x-1][y+1] == '0' && show[x-1][y+1] == '*' && x-1 >= 1 && y+1 >= 1 && x-1 <= row && y+1 <= col)
	{
		show[x-1][y+1] = get_Leinum(mine, x-1, y+1)+'0';
		if (get_Leinum(mine, x - 1, y + 1) == 0)
		{
			Openboard(mine, show,row,col, x - 1, y + 1);
		}
	}	
	if (mine[x][y-1] == '0' && show[x][y-1] == '*' && x >= 1 && y-1 >= 1 && x <= row && y-1 <= col)
	{
		show[x][y-1] = get_Leinum(mine, x, y-1)+'0';
		if (get_Leinum(mine, x, y - 1) == 0)
		{
			Openboard(mine, show,row,col, x, y - 1);
		}
	}
	if (mine[x][y+1] == '0' && show[x][y+1] == '*' && x >= 1 && y+1 >= 1 && x <= row && y+1 <= col)
	{
		show[x][y+1] = get_Leinum(mine, x, y+1)+'0';
		if (get_Leinum(mine, x , y + 1) == 0)
		{
			Openboard(mine, show,row,col, x , y + 1);
		}
	}	
	if (mine[x+1][y-1] == '0' && show[x+1][y-1] == '*' && x+1 >= 1 && y-1 >= 1 && x+1 <= row && y-1 <= col)
	{
		show[x+1][y-1] = get_Leinum(mine, x+1, y-1)+'0';
		if (get_Leinum(mine, x + 1, y - 1) == 0)
		{
			Openboard(mine, show,row,col, x + 1, y - 1);
		}
	}	
	if (mine[x+1][y] == '0' && show[x+1][y] == '*' && x+1 >= 1 && y >= 1 && x+1 <= row && y <= col)
	{
		show[x+1][y] = get_Leinum(mine, x+1, y)+'0';
		if (get_Leinum(mine, x + 1, y ) == 0)
		{
			Openboard(mine, show,row,col, x + 1, y );
		}
	}	
	if (mine[x+1][y+1] == '0' && show[x+1][y+1] == '*' && x+1 >= 1 && y+1 >= 1 && x+1 <= row && y+1 <= col)
	{
		show[x+1][y+1] = get_Leinum(mine, x+1, y+1)+'0';
		if (get_Leinum(mine, x + 1, y + 1) == 0)
		{
			Openboard(mine, show,row,col, x + 1, y + 1);
		}
	}	
}


int get_Leinum(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
	mine[x - 1][y] +
	mine[x - 1][y + 1] +
	mine[x][y - 1] +
	mine[x][y + 1] +
	mine[x + 1][y - 1] +
	mine[x + 1][y] +
	mine[x + 1][y + 1] - 8 * '0';
}


void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count =0;
	while (count< row * col - Leinum)
	{
		printf("请输入排查坐标》:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("踩雷了！你挂了！\n");
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				//int ret = get_Leinum(mine,x,y);   //计算周围雷的数量
				//show[x][y] = ret+'0';
				Openboard(mine, show,row,col, x, y);
				Displayboard(show, row, col);
				count++;
			}

		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (count == row * col - Leinum)
		printf("牛逼，扫雷成功！\n");
}
