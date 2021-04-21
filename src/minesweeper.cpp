#include <bits/stdc++.h>
#include <stdlib.h>
#include <utility>
#include <vector> 
using namespace std;


int NROWS;
int NCOLUMNS;
int MINES;

const int BEGINNER = 0;
const int INTERMEDIATE = 1;
const int ADVANCED = 2;
const int MAXSIDE = 30;


void chooseDifficultyLevel(){
    
    int level;
    cout << "Enter the Difficulty Level: " << endl;
    cout << "Press 0 for BEGINNER     (9  * 9 cells and 10 mines)" << endl;
    cout << "Press 1 for INTERMEDIATE (16 * 16 cells and 40 mines)" << endl;
    cout << "Press 2 for ADVANCED     (16 * 30 cells and 99 mines)" << endl;

    cin >> level;

    if(level == BEGINNER){
        NROWS = 9;
        NCOLUMNS = 9;
        MINES = 10;
    }
    if(level == INTERMEDIATE){
        NROWS = 16;
        NCOLUMNS = 16;
        MINES = 40;
    }

    if(level == ADVANCED){
        NROWS = 16;
        NCOLUMNS = 30;
        MINES = 99;
    }

    return;
}

void ClearBoards(char MineBoard[][MAXSIDE], char GameBoard[][MAXSIDE]){
    for(int i=0; i < NROWS; i++)
        for(int j=0; j < NCOLUMNS; j++)
            GameBoard[i][j] = MineBoard[i][j] = '.';
    return;
}

void placeMines(char MineBoard[][MAXSIDE], int mines){
    int placed = 0;
    while(placed < mines){
        int random = rand() % (NROWS * NCOLUMNS);
        int row = random / NCOLUMNS;
        int col = random % NROWS;
        if(MineBoard[row][col] == '#') continue; //already a mine
        MineBoard[row][col] = '#';
        placed++;
    }
    return;
}

void replaceMine(int row, int col, char MineBoard[][MAXSIDE]){
    placeMines(MineBoard, 1); //add new line
    MineBoard[row][col] = '.'; //remove the old one
    return;
}

char indexTochar(int index){
    if(index <10) return index + '0';
    else return 'a' + (index - 10);
}

int charToindex(char ch){
    if(ch <= '9') return ch - '0';
    else return (ch - 'a') + 10;
}

void displayBoard(char GameBoard[][MAXSIDE]){
    //top line
    cout << "    ";
    for(int i=0; i < NCOLUMNS; i++)
        cout << indexTochar(i) << ' ';
    cout << endl << endl;

    //rows
    for(int i=0; i < NROWS; i++){
        cout << indexTochar(i) << "   ";
        for(int j=0; j < NCOLUMNS; j++)
        cout << GameBoard[i][j] << " ";
        cout << " " << indexTochar(i);
        cout << endl;
    }

    //bottom line
    cout << endl << "    ";
    for(int i=0; i<NCOLUMNS; i++)
        cout << indexTochar(i) << ' ';
    cout << endl;

    return;
}

bool isVaid(int row, int col){
    return(row >= 0) && (row < NROWS) && (col >=0) && (col < NCOLUMNS); //whether or not (row, col ) is within the bounds of the game
}

bool isMine(int row, int col, char board[][MAXSIDE]){
  return(board[row][col] == '#');  
}

//Arrrgghhhh! wuubbb wuubbbb remember thiisss!
//return vector of all neighbours of row,col
vector < pair <int,int> > getNeighbours(int row, int col){
    vector < pair <int, int> > neighbours;
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++)
            if(dx != 0 || dy != 0)
                if(isVaid(row+dx, col+dy))
                neighbours.push_back(make_pair(row+dx, col+dy));
    }
    return neighbours;
}

//count the number of mines in the ajacent cells
int countAdjacentMines(int row, int col, char MineBoard[][MAXSIDE]){
    vector < pair <int,int> > neighbours = getNeighbours(row, col);

    int count = 0;
    for(int i=0; i < neighbours.size(); i++)
        if(isMine(neighbours[i].first, neighbours[i].second, MineBoard))
            count++;

    return count;        
}

//reveal the square at (row, col) 
void uncoverBoard(char GameBoard[][MAXSIDE], char MineBoard[][MAXSIDE], int row, int col, int *nmoves){
    (*nmoves)++;
    int count = countAdjacentMines(row, col, MineBoard);
    GameBoard[row][col] = count + '0';
    //if cell number = 0 uncover all the neighbouring cells (only uncover if neighbour == '.')
    if(count == 0){
    vector < pair <int,int> > neighbours = getNeighbours(row, col);
        
        for(int i=0; i <= neighbours.size(); i++)
            if(GameBoard[neighbours[i].first][neighbours[i].second] == '.')
                uncoverBoard(GameBoard, MineBoard, neighbours[i].first, neighbours[i].second, nmoves);
    }

    return;
}

//mark all mines on board using # depending on whether won is true/false
void markMines(char GameBoard[][MAXSIDE], char MineBoard[][MAXSIDE], bool won){
    for(int i=0; i < NROWS; i++){
        for(int j=0; j < NCOLUMNS; j++){
            if(GameBoard[i][j] == '.' && MineBoard[i][j] == '#'){
                if(won){
                    GameBoard[i][j] == 'F';
                }
                else{
                    GameBoard[i][j] == '#';
                }
            }        
        }
    }
}

void playMinesweeper(){
    //intialization
    char MineBoard[MAXSIDE][MAXSIDE], GameBoard[MAXSIDE][MAXSIDE];
    int nmovestotal = NROWS * NCOLUMNS - MINES;
    int flags = MINES;
    ClearBoards(MineBoard, GameBoard);
    placeMines(MineBoard, MINES);

    //let's play!
    int nmoves = 0;
    bool gameOver = false;

    while(!gameOver){
        displayBoard(GameBoard);
        cout << flags << " flags left" << endl << endl;

        //take input
        char x, y, z;
        cout << "Enter your move, (row, column, safe(s)/flag(f)) -> ";
        cin >> x >> y >> z;
        cout << endl;

        int row = charToindex(x);
        int col = charToindex(y);

        if(nmoves == 0){
            if(isMine(row, col, MineBoard))
                replaceMine(row, col, MineBoard);
        }
        
        if(z == 's'){
            if(GameBoard[row][col] == '.' && MineBoard[row][col] == '.'){ 
                uncoverBoard(GameBoard, MineBoard, row, col, &nmoves);
                if(nmoves == nmovestotal){
                    markMines(GameBoard, MineBoard, true);
                    displayBoard(GameBoard);
                    cout << endl << "Yippppe! You won!" << endl;
                    gameOver = true; 
                }
                 

            }
            else if (GameBoard[row][col] == '.' && MineBoard[row][col] == '#'){
                //game over
                GameBoard[row][col] = '#';
                markMines(GameBoard, MineBoard, false);
                displayBoard(GameBoard);
                cout << endl << "You lost! Better luck next time! Keeps hope high! " << endl;
                gameOver = true;
            }
            else {
                //illegal move
                cout << "Illegal Move. ";
                if(GameBoard[row][col] == 'F')
                    cout << "Cell is is a flag. Use f to toggle flag off. ";
                else 
                    cout << "Cell is already a number. ";
                cout << endl;
            }
             
        }

       else if(z == 'f'){ 
           if(GameBoard[row][col] == '.'){
               if(flags != 0){
                   GameBoard[row][col] = 'F';
                   flags--;
               }
               else cout << "Illegal move. Too many flags! " << endl;
           }
           else if(GameBoard[row][col] == 'F') {
                //undo a flag
                GameBoard[row][col] = '.';
                flags++;
           }
           else cout << "Illegal Move. Cell is a number. " << endl; //illegal move
        }
    }
    return;
}

int main(){

    srand(time(NULL));
    chooseDifficultyLevel();
    playMinesweeper();
    return 0;

} 