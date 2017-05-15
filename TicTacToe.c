#include <stdio.h>
#include <stdlib.h>

int turn = 1;
char board[3][3];

void initBoard();
void printBoard();
void move(int t);
void victory(char c);






/*
    Tic Tac Toe is a simple game

    Played by two players
    On a 3x3 Board which has 9 squares in total
    X is the first to move and moves 5 times
    O moves only 4 times
    There are 9 turns in TTT

    On the Fifth Turn we can start checking for victory conditions
    On the Ninth turn it is either a Win, Loss or Draw


*/


int main() {
    initBoard();
    printBoard();

    while (1) {
        move(turn);
    }

}

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '#';
        }
    }
}

void printBoard() {
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          printf("%c", board[j][i]);
      }
      printf("\n");
  }
  printf("********\n********\n");

}

void move(int t) {
    char c;
    if (t % 2 == 0) {
        c = 'O';
    } else {
        c = 'X';
    }


    int x, y;

    printf("This is turn number %d\n", turn);
    printf("It is %c's turn to move\n", c);
    printf("Please enter coordinates\n");

    scanf(" %d", &x);
    scanf(" %d", &y);

    if (board[x-1][y-1] != '#') {
        printf("This is not a valid move\n");
        return;
    }

    board[x-1][y-1] = c;



    printBoard();

    if (turn > 4) {
        victory(c);
    }
    turn++;
}

void victory(char c) {



    printf("\n\nThis is turn %d\nAnd we are checking for victory for %c", turn, c);

    if ( (board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) ||
         (board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) ||
         (board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) ||

         (board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) ||
         (board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) ||
         (board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) ||

         (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) ||
         (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
           printf("\n\nCONGRATULATIONS PLAYER %c\n YOU ARE THE WINNER!\n\n", c);
           exit(0);
         }







}
