#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int board[SIZE][SIZE];

bool row[SIZE][SIZE + 1];
bool col[SIZE][SIZE + 1];
bool box[SIZE / 3][SIZE + 1];

// 3*3¹¬Ë÷Òý
int getBoxIndex(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        for (int num = 1; num <= SIZE; num++) {
            row[i][num] = false;
            col[i][num] = false;
            box[i][num] = false;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = board[i][j];
            if (num != 0) {
                row[i][num] = true;
                col[j][num] = true;
                box[getBoxIndex(i, j)][num] = true;
            }
        }
    }
}

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

bool isValid(int i, int j, int num) {
    int k = getBoxIndex(i, j);
    return !row[i][num] && !col[j][num] && !box[k][num];
}

bool solveSudoku(int i, int j) {
	
    if (i == SIZE) return true;
    if (j == SIZE) return solveSudoku(i + 1, 0);
    if (board[i][j] != 0) return solveSudoku(i, j + 1);

    int k = getBoxIndex(i, j);
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(i, j, num)) {
        	
            board[i][j] = num;
            row[i][num] = true;
            col[j][num] = true;
            box[k][num] = true;

            if (solveSudoku(i, j + 1)) return true;

            board[i][j] = 0;
            row[i][num] = false;
            col[j][num] = false;
            box[k][num] = false;
        }
    }
    return false;
}

int main() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    init();

    if (solveSudoku(0, 0)) {
        printSudoku();
    } else {
        printf("No solution\n");
    }

    return 0;
}
