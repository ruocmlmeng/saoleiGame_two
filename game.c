/**
  ******************************************************************************
  * @file           : game.c
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/9
  ******************************************************************************
  */

#include "game.h"



//初始化棋盘
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < rows ;i++)
  {
    for (j = 0; j < cols ; j++)
    {
      board[i][j] = set;
    }
  }
}

//展示棋盘
void DisPlayBoard(char board[ROWS][COLS],int row,int col)
{
  int x = 0;
  int y = 0;
  printf("-------扫雷游戏------\n");
  for (y = 0 ; y <= col ;y++)
  {
    printf("%d ",y);
  }
  printf("\n");
  for (x = 1; x <= row ; x++)
  {
    printf("%d ",x);
    for (y = 1; y <=col ;y++)
    {
      printf("%c ",board[x][y]);
    }
    printf("\n");
  }
  printf("-------扫雷游戏------\n");
}

//开始布雷
void SetMine(char board[ROWS][COLS],int row,int col)
{
  int count = EASY_MINE;
  int x = 0;
  int y = 0;
  while (count != 0)
  {

    //设置随机坐标来放置雷
     x = rand() % row + 1;//1~9
     y = rand() % col + 1;//1~9
    if(board[x][y] != '1')
    {
      board[x][y] = '1';
      count--;
    }
  }
}

//计算输入坐标周围的雷数
int Count_mine(char board[ROWS][COLS],int x,int y)
{
  return (board[x - 1][y] +
          board[x - 1][y - 1]+
            board[x][y - 1] +
              board[x + 1][y - 1]+
                board[x + 1][y] +
                  board[x + 1][y + 1] +
                    board[x][y + 1] +
                      board[x - 1][y + 1] - 8*'0');
}

//开始排雷-核心逻辑
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
  int x = 0;
  int y = 0;
  int win = 0;//判断赢的条件
  while (win < row * col - EASY_MINE)
  {
    printf("请输入坐标:>");
    scanf("%d %d",&x,&y);
    if(x>=1 && x <=row && y >=1 && y <= col)
    {
      if( show[x][y] != '*')
      {
        printf("该坐标被排查过了,请重新输入坐标\n");
      }
      else
      {
        if(mine[x][y] == '1')
        {
          printf("很遗憾,你踩到雷了,游戏结束!\n");
          break;
        }else
        {
            win++;
            int count = Count_mine(mine,x,y);
            show[x][y] = count  + '0';
            DisPlayBoard(show,ROW,COL);
            //选择插旗还是继续排雷
            Choice_game(mine,show,ROW,COL);
        }
      }
    }
    else
    {
      printf("输入不合法请重新输入!\n");
    }
    if(win == row * col - EASY_MINE)
    {
      printf("恭喜你排雷成功,游戏胜利!\n");
      DisPlayBoard(mine,ROW,COL);
    }
  }
}

//插旗逻辑
void FlagMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
  printf("请选择要插旗的坐标");
  int x = 0;
  int y = 0;
  scanf("%d %d",&x,&y);
  if(x >=1 && x <=row && y >=1 && y <=col)
  {
    if(show[x][y] == '*')
    {
      show[x][y] = '!';
      printf("在(%d,%d)处插旗成功!\n",x,y);
    }
    else if(show[x][y] =='!')
    {
      show[x][y] = '*';
      printf("在(%d,%d)处取消插旗!\n",x,y);
    }
    else
    {
      printf("该位置已经排查过了,请选择其他操作.\n");
    }
  }
  else
  {
    printf("输入的坐标不合法,请重新输入");
  }
}


//选择插旗还是继续排雷
void Choice_game(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
  int choice = 0;
  do
  {
    printf("请选择操作:>\n");
    printf("1.继续排雷\n");
    printf("2.插旗\n");
    printf("0.提前结束游戏\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        //继续排雷
        FindMine(mine,show,ROW,COL);
        break;
      case 2:
        //插旗
        FlagMine(mine,show,ROW,COL);
        DisPlayBoard(show,ROW,COL);
        break;
      case 0:
        printf("游戏结束!\n");
      break;
      default:
        printf("输入有误请重新输入!\n");
      break;
    }
  } while (choice);
}