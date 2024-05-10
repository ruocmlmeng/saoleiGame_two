/**
  ******************************************************************************
  * @file           : game.h
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/9
  ******************************************************************************
  */

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EASY_MINE 30//雷的个数

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2


//初始化棋盘
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

//展示棋盘
void DisPlayBoard(char board[ROWS][COLS],int row,int col);

//开始布雷
void SetMine(char board[ROWS][COLS],int row,int col);

//开始排雷-核心逻辑
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

//插旗逻辑
void FlagMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

//选择插旗还是继续排雷
void Choice_game(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col);
#endif //GAME_H
