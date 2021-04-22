from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp cimport bool

cdef extern from "../src/minesweeper.h":
    int NROWS;
    int NCOLUMNS;
    int MINES;
    void chooseDifficultyLevel();
    void ClearBoards(char **MineBoard, char **GameBoard);
    void placeMines(char **MineBoard, int mines);
    void replaceMine(int row, int col, char **MineBoard);
    char indexTochar(int index);
    int charToindex(char ch);
    void displayBoard(char **GameBoard);
    bool isVaid(int row, int col);
    bool isMine(int row, int col, char **board);
    vector[pair[int,int]] getNeighbours(int row, int col);
    int countAdjacentMines(int row, int col, char **MineBoard);
    void uncoverBoard(char **GameBoard, char **MineBoard, int row, int col, int *nmoves);
    void markMines(char **GameBoard, char **MineBoard, bool won);
    void playMinesweeper();

cpdef pychooseDifficultyLevel():
    chooseDifficultyLevel()

cpdef pyplayMinesweeper():
    playMinesweeper()