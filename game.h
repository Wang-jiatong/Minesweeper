#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define NUM 10//雷的数量


//初始化
void InitBoard(char board[ROWS][COLS],int rows,int cols,char ch); 
//显示显示盘
void DisplayBoard(char board[ROWS][COLS],int row,int col);  
//布置雷
void SetMine(char board[ROWS][COLS],int row,int col);
//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col); 
//统计周围有几个雷
int MineAround(char mine[ROWS][COLS],int x,int y);
//判断是否排查了所有雷
int IsWin(char show[ROWS][COLS],char mine[ROWS][COLS],int row,int col);
//扩展排查
void Expand(char show[ROWS][COLS],char mine[ROWS][COLS],int row,int col,int x,int y);




