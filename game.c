#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char ch){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            board[i][j]=ch;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS],int row,int col){
    for(int j=0;j<=col;j++){
        printf("%d ",j);
    }
    printf("\n");
    for(int i=1;i<=row;i++){
        printf("%d ",i);
        for(int j=1;j<=col;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char board[ROWS][COLS],int row,int col){
    int count=0;
    while(count<NUM){
        int x=rand()%row+1;
        int y=rand()%col+1;
        if(board[x][y]=='0'){
            board[x][y]='1';
            count++;
        }
    }
}
    
int MineAround(char mine[ROWS][COLS],int x,int y){
    return mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+mine[x][y-1]+mine[x][y+1]+mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]-'0'*8;
}

int IsWin(char show[ROWS][COLS],char mine[ROWS][COLS],int row,int col){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(mine[i][j]=='0'&&show[i][j]=='*'){
                return 0;
            }
        }
    }
    return 1;
}

void Expand(char show[ROWS][COLS],char mine[ROWS][COLS],int row,int col,int x,int y){
    //如果坐标处是空格，就把周围一圈的坐标也打开
    //打开的位置显示周围有几个雷
    //如果周围没有雷，就把该位置显示为空格，并递归打开周围一圈的坐标
    //如果周围有雷，就把该位置显示为雷的数量，并不递归打开周围一圈的坐标
    //为了防止重复打开，要判断该位置是否已被打开
    //注意：坐标x,y在显示盘的范围是1到row，1到col
    int count=MineAround(mine,x,y);
    if(count==0){
        show[x][y]=' ';
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(show[i][j]=='*'&&i>0&&i<=row&&j>0&&j<=col){
                    Expand(show,mine,row,col,i,j);
                }
            }
        }
    }
    else
        show[x][y]=count+'0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y){
    
    while(1){
        if(x>=1&&x<=row&&y>=1&&y<=col){
            if(show[x][y]=='*'){
                if(mine[x][y]=='1'){
                    printf("很遗憾，你踩到雷了！\n");
                    DisplayBoard(mine,ROW,COL);
                    break;
                }
                else{
                    Expand(show,mine,ROW,COL,x,y);
                    system("cls");
                    DisplayBoard(show,ROW,COL);
                    //判断是否排查了所有雷
                    if(IsWin(show,mine,ROW,COL)){
                        printf("恭喜你，你排查了所有雷！\n");
                        DisplayBoard(mine,ROW,COL);
                        break;
                    }
                }

            }
            else{
                printf("该坐标已被打开！\n");
            }
        }
        else{
            printf("坐标非法！请重新输入！\n");
        }
        printf("请输入要排查的坐标：");
        scanf("%d %d",&x,&y);
    }

}