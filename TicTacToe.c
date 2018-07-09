#include <stdio.h>
#include <stdlib.h>

#define length 3
#define size   9

int turn = 1;
char board[length];

void initBoard();
void printBoard();
void move(int t);
void victory(char c);
void end(char c);

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
    for (int i = 0; i < size; i++) {
        board[i] = '1' + i;        
    }
}

void printBoard() {
  
  printf("\n");

  for (int i = 0; i < size; i++) {
      printf("%c", board[i]);
      
      if ( (i + 1) % 3 == 0) {
        printf("\n");
      }
  }
  printf("********\n********\n");
}

void move(int t) {
    
    char piece;
    
    if (t % 2 == 0) {
        piece = 'O';
    } else {
        piece = 'X';
    }

    int x;

    printf("This is turn number %d.\n", turn);
    printf("It is %c's turn to move.\n", piece);
    printf("Please enter the Square Number.\n");

    scanf(" %d", &x);

    // Could alternatively use the isdigit() function.
    if (board[x - 1] == 'O' || board[x - 1] == 'X') {
        printf("This is not a valid move\n");
        return;
    }

    board[x - 1] = piece;

    printBoard();

    if (turn > 4) {
        victory(piece);
    }
    turn++;
}

void victory(char c) {

    printf("\n\nThis is turn %d\nAnd we are checking for victory for %c.", turn, c);

    for (int i = 0; i < size; i += 3) {
    	if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
			end(c);
      	}    
    }

    for (int i = 0; i < length; i++) {
      	if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
			end(c);
      	} 
    }

    if (board[0] == board [4] && board[0] == board[8]) {
      	end(c);
    }

    if (board[2] == board [4] && board[0] == board[6]) {
      	end(c);
    }

}

void end(char c) {
	printf("\n\nCONGRATULATIONS PLAYER %c\n YOU ARE THE WINNER!\n\n", c);
    exit(0);
}
