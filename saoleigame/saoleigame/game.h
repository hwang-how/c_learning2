#pragma once
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define ROW 9
# define COL 9
# define ROWS ROW+2
# define COLS COL+2 
# define Leinum 10 //布置雷的数量

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setmine(char board[ROWS][COLS], int row, int col);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col, int x, int y);
int get_Leinum(char mine[ROWS][COLS], int x, int y);