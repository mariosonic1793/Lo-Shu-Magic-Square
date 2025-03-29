#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool searchSquare(int square[3][3]) {
    int total = 0;
    int n = 1;
    while (n <= 9) {
        bool found = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (square[i][j] == n) {
                    if (found) {
                        return false;
                    }
                    total++;
                    found = true;
                }
            }
        }
        n++;
    }
    return (total == 9);
}

bool isMagicSquare(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        if ((square[i][0] + square[i][1] + square[i][2]) != 15) return false;
        if ((square[0][i] + square[1][i] + square[2][i]) != 15) return false;
    }
    if ((square[0][0] + square[1][1] + square[2][2]) != 15) return false;
    if ((square[0][2] + square[1][1] + square[2][0]) != 15) return false;
    return true;
}

int main() {
    int isSquare[3][3] = {{4,9,2}, {3,5,7}, {8,1,6}};
    if (isMagicSquare(isSquare)) {
        printf("[4 9 2]\n[3 5 7] is a Lo Shu Magic Square\n[8 1 6]\n\n");
    } else {
        printf("This program is not working :(\n\n");
    }
    int isntSquare[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    if (isMagicSquare(isntSquare)) {
        printf("This program is not working :(\n\n");
    } else {
        printf("[1 2 3]\n[4 5 6] is NOT a Lo Shu Magic Square\n[7 8 9]\n\n");
    }

    srand(time(0));
    int attempts = 0;
    int square[3][3];

    do {
        int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for (int i = 0; i < 9; i++) {
            int j = rand() % 9;
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }

        // Fill the square with the shuffled numbers
        int idx = 0;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                square[a][b] = numbers[idx++];
            }
        }
        attempts++;
    } while (!isMagicSquare(square));
    printf("It took %d attempts to make a Lo Shu Magic Square\n", attempts);
    printf("[%d %d %d]\n[%d %d %d] is a Lo Shu Magic Square\n[%d %d %d]", 
        square[0][0], square[0][1], square[0][2],
        square[1][0], square[1][1], square[1][2],
        square[2][0], square[2][1], square[2][2]);
}