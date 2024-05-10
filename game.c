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



//��ʼ������
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

//չʾ����
void DisPlayBoard(char board[ROWS][COLS],int row,int col)
{
  int x = 0;
  int y = 0;
  printf("-------ɨ����Ϸ------\n");
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
  printf("-------ɨ����Ϸ------\n");
}

//��ʼ����
void SetMine(char board[ROWS][COLS],int row,int col)
{
  int count = EASY_MINE;
  int x = 0;
  int y = 0;
  while (count != 0)
  {

    //�������������������
     x = rand() % row + 1;//1~9
     y = rand() % col + 1;//1~9
    if(board[x][y] != '1')
    {
      board[x][y] = '1';
      count--;
    }
  }
}

//��������������Χ������
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

//��ʼ����-�����߼�
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
  int x = 0;
  int y = 0;
  int win = 0;//�ж�Ӯ������
  while (win < row * col - EASY_MINE)
  {
    printf("����������:>");
    scanf("%d %d",&x,&y);
    if(x>=1 && x <=row && y >=1 && y <= col)
    {
      if( show[x][y] != '*')
      {
        printf("�����걻�Ų����,��������������\n");
      }
      else
      {
        if(mine[x][y] == '1')
        {
          printf("���ź�,��ȵ�����,��Ϸ����!\n");
          break;
        }else
        {
            win++;
            int count = Count_mine(mine,x,y);
            show[x][y] = count  + '0';
            DisPlayBoard(show,ROW,COL);
            //ѡ����컹�Ǽ�������
            Choice_game(mine,show,ROW,COL);
        }
      }
    }
    else
    {
      printf("���벻�Ϸ�����������!\n");
    }
    if(win == row * col - EASY_MINE)
    {
      printf("��ϲ�����׳ɹ�,��Ϸʤ��!\n");
      DisPlayBoard(mine,ROW,COL);
    }
  }
}

//�����߼�
void FlagMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
  printf("��ѡ��Ҫ���������");
  int x = 0;
  int y = 0;
  scanf("%d %d",&x,&y);
  if(x >=1 && x <=row && y >=1 && y <=col)
  {
    if(show[x][y] == '*')
    {
      show[x][y] = '!';
      printf("��(%d,%d)������ɹ�!\n",x,y);
    }
    else if(show[x][y] =='!')
    {
      show[x][y] = '*';
      printf("��(%d,%d)��ȡ������!\n",x,y);
    }
    else
    {
      printf("��λ���Ѿ��Ų����,��ѡ����������.\n");
    }
  }
  else
  {
    printf("��������겻�Ϸ�,����������");
  }
}


//ѡ����컹�Ǽ�������
void Choice_game(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
  int choice = 0;
  do
  {
    printf("��ѡ�����:>\n");
    printf("1.��������\n");
    printf("2.����\n");
    printf("0.��ǰ������Ϸ\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        //��������
        FindMine(mine,show,ROW,COL);
        break;
      case 2:
        //����
        FlagMine(mine,show,ROW,COL);
        DisPlayBoard(show,ROW,COL);
        break;
      case 0:
        printf("��Ϸ����!\n");
      break;
      default:
        printf("������������������!\n");
      break;
    }
  } while (choice);
}