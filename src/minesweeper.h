#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <vector> 

using namespace std;

const int BEGINNER = 0;
const int INTERMEDIATE = 1;
const int ADVANCED = 2;
const int MAXSIDE = 30;

void chooseDifficultyLevel();
void ClearBoards(char MineBoard[][MAXSIDE], char GameBoard[][MAXSIDE]);
void placeMines(char MineBoard[][MAXSIDE], int mines);
void replaceMine(int row, int col, char MineBoard[][MAXSIDE]);
char indexTochar(int index);
int charToindex(char ch);
void displayBoard(char GameBoard[][MAXSIDE]);
bool isVaid(int row, int col);
bool isMine(int row, int col, char board[][MAXSIDE]);
vector < pair <int,int> > getNeighbours(int row, int col);
int countAdjacentMines(int row, int col, char MineBoard[][MAXSIDE]);
void uncoverBoard(char GameBoard[][MAXSIDE], char MineBoard[][MAXSIDE], int row, int col, int *nmoves);
void markMines(char GameBoard[][MAXSIDE], char MineBoard[][MAXSIDE], bool won);
void playMinesweeper();

#endif