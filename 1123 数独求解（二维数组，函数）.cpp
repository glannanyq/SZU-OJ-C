#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int board[SIZE][SIZE];

void printSudoku() {
	
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
          	if (j < 8){
              	printf(" ");
            }
        }
        printf("\n");
    }
}

bool isValid(int row, int col, int num) {
	
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;
    }

    for (int x = 0; x < 9; x++) {
        if (board[x][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool solveSudoku() {
	
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
        	
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                	
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        // µÝ¹é
                        if (solveSudoku()) {
                            return true;
                        }
                        // »ØËÝ
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solveSudoku()) {
        printSudoku();
    } else {
        printf("No solution\n");
    }

    return 0;
}
