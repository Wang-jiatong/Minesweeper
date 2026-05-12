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

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){
    int x=0;
    int y=0;
    int ret=0;

    while(1){
        printf("请输入要排查的坐标：");
        scanf("%d %d",&x,&y);

        if(x>=1&&x<=row&&y>=1&&y<=col){
            if(show[x][y]=='*'){
                if(mine[x][y]=='1'){
                    printf("很遗憾，你踩到雷了！\n");
                    DisplayBoard(mine,ROW,COL);
                    break;
                }
                else{
                    ret++;
                    //判断是否排查了所有雷
                    if(ret==row*col-NUM){
                        printf("恭喜你，你排查了所有雷！\n");
                        DisplayBoard(mine,ROW,COL);
                        break;
                    }
                    //统计周围有几个0
                    int count=MineAround(mine,x,y);
                    show[x][y]=count+'0';
                    DisplayBoard(show,ROW,COL);
                }

            }
            else{
                printf("该坐标已被打开！\n");
            }
        }
        else{
            printf("坐标非法！请重新输入！\n");
        }
    }

}