# define _CRT_SECURE_NO_WARNINGS 1
# include "game.h"

void menu()
{
	printf("********************************\n");
	printf("**********  1.play   ***********\n");
	printf("**********  0.exit   ***********\n");
	printf("********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };  // 用来布置雷的数组
	char show[ROWS][COLS] = { 0 };  // 用来显示点击后结果的的数组
	Initboard(mine, ROWS, COLS, '0');  //初始化雷数组
	Initboard(show, ROWS, COLS, '*');  //初始化显示数组
	Displayboard(show, ROW, COL); //打印扫雷棋盘
	//Displayboard(mine, ROW, COL);
	Setmine(mine, ROW, COL);   //布置雷函数
	/*Displayboard(mine, ROW, COL);*/
	Findmine(mine, show, ROW, COL);  //扫雷
}

void test()
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
}


int main()
{
	test();
	return 0;
}