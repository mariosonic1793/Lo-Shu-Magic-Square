#include <stdio.h>
#include <stdbool.h>

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
    if (searchSquare(square)) {
        if (square[0][0] + square[0][1] + square[0][2] == 15) {
            if (square[1][0] + square[1][1] + square[1][2] == 15) {
                if (square[2][0] + square[2][1] + square[2][2] == 15) {
                    if (square[0][0] + square[1][0] + square[2][0] == 15) {
                        if (square[0][1] + square[1][1] + square[2][1] == 15) {
                            if (square[0][2] + square[1][2] + square[2][2] == 15) {
                                if (square[0][0] + square[1][1] + square[2][2] == 15) {
                                    if (square[2][0] + square[1][1] + square[0][2] == 15) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
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
}