#include "game.h"

void menu(){
    printf("###########-扫雷游戏-###########\n");
    printf("###########1.简单模式###########\n");
    printf("###########2.困难模式###########\n");
    printf("###########0.退出游戏###########\n");

   }

void game(){
    system("cls");
    printf("游戏开始\n");
    char mine[ROWS][COLS]={0};//雷盘
    char show[ROWS][COLS]={0};//显示盘
    //初始化
    //mine在没有布置雷时，所有元素都为'0'
    //show在没有布置显示盘时，所有元素都为'*'
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    DisplayBoard(show,ROW,COL);

    //布置雷
    SetMine(mine,ROW,COL);
    //排查雷
    FindMine(mine,show,ROW,COL);

}

int main(){
    int input=0;
    srand((unsigned int)time(NULL));

    do{
        menu();
        printf("请输入选择：");
        scanf("%d",&input);
        switch(input){
            case 1:
                printf("简单模式\n");
                game();
                break;
            case 2:
                printf("困难模式\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误!请重新输入：\n");
                break;
        }


    }while(input);
}