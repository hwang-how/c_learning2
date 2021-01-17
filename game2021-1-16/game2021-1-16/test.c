# define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include "game.h"

//三子棋游戏

void menu()
{
	printf("****************************\n");
	printf("****1.play        0.exit****\n");
	printf("****************************\n");

}
//  游戏实现函数
void game()
{
	char board[ROW][COL] = { 0 };
	// 初始化棋盘
	Initboard(board, ROW, COL);    //这里相当于已经在传参数了，这个函数的实现在game.c里面
	// 布置棋盘
    //   |   |   
    //---|---|---
    //   |   |   
    //---|---|---
    //   |   |   
	Displayboard(board, ROW, COL);
	char ret = '0';
	while (1)
	{
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家胜!!!\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜!!!\n");
	}
	else
	{
		printf("和棋!!!\n");
	}
	// 玩家下棋
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("即将开始三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;

		}
	} while (input);
	return 0;
}