#include "game.h"
//创建游戏开始的菜单
void menu()
{
    printf("******************************\n");
    printf("********  1.play   ***********\n");
    printf("********  0.exit   ***********\n");
    printf("******************************\n");
}

//开始游戏的函数
void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    //初始化棋盘
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');
    //展示棋盘
    // DisPlayBoard(mine,ROW,COL);
    // DisPlayBoard(show,ROW,COL);
    //开始布雷
    SetMine(mine,ROW,COL);
    DisPlayBoard(mine,ROW,COL);

    //开始排雷-核心逻辑
    FindMine(mine,show,ROW,COL);
    // DisPlayBoard(show,ROW,COL);


}
int main()
{
    //随机数发生器的初始化函数
    srand((unsigned int )time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("请输入你的选择:>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                //开始游戏的函数
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误请重新输入\n");
                break;
        }
    } while (input);

    return 0;
}
//以上实现的是基本功能
//可以扩展
//1.标记雷的功能
//2.展开一片的功能
//  排查x,y坐标的时候:
//  1.该坐标不是雷
//  2.该坐标周围没有雷
//  3.该坐标没用被排查过