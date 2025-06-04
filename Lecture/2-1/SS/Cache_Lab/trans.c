#include "cachelab.h"
#include <stdio.h>

void registerTransFunction(void (*trans)(int M, int N, int[N][M], int[M][N]), char *desc);

char transposesubmit_desc[] = "Transpose submission";

void transposesubmit(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, k, l, tmp, diag;
    if (M == 32 && N == 32) {
        for (i = 0; i < 32; i += 8) {
            for (j = 0; j < 32; j += 8) {
                for (k = i; k < i + 8; ++k) {
                    diag = -1;
                    for (l = j; l < j + 8; ++l) {
                        if (k != l)
                            B[l][k] = A[k][l];
                        else {
                            tmp = A[k][l];
                            diag = k;
                        }
                    }
                    if (diag != -1)
                        B[diag][diag] = tmp;
                }
            }
        }
    } else if (M == 64 && N == 64) {
        int a1, a2, a3, a4, a5, a6, a7, a8;
        for (i = 0; i < 64; i += 8) {
            for (j = 0; j < 64; j += 8) {
                for (k = 0; k < 4; ++k) {
                    a1 = A[i + k][j + 0];
                    a2 = A[i + k][j + 1];
                    a3 = A[i + k][j + 2];
                    a4 = A[i + k][j + 3];
                    a5 = A[i + k][j + 4];
                    a6 = A[i + k][j + 5];
                    a7 = A[i + k][j + 6];
                    a8 = A[i + k][j + 7];

                    B[j + 0][i + k] = a1;
                    B[j + 1][i + k] = a2;
                    B[j + 2][i + k] = a3;
                    B[j + 3][i + k] = a4;

                    B[j + 0][i + k + 4] = a5;
                    B[j + 1][i + k + 4] = a6;
                    B[j + 2][i + k + 4] = a7;
                    B[j + 3][i + k + 4] = a8;
                }
                for (k = 0; k < 4; ++k) {
                    a1 = A[i + 4][j + k];
                    a2 = A[i + 5][j + k];
                    a3 = A[i + 6][j + k];
                    a4 = A[i + 7][j + k];

                    a5 = B[j + k][i + 4];
                    a6 = B[j + k][i + 5];
                    a7 = B[j + k][i + 6];
                    a8 = B[j + k][i + 7];

                    B[j + k][i + 4] = a1;
                    B[j + k][i + 5] = a2;
                    B[j + k][i + 6] = a3;
                    B[j + k][i + 7] = a4;

                    B[j + k + 4][i + 0] = a5;
                    B[j + k + 4][i + 1] = a6;
                    B[j + k + 4][i + 2] = a7;
                    B[j + k + 4][i + 3] = a8;
                }
                for (k = 4; k < 8; ++k) {
                    for (l = 4; l < 8; ++l) {
                        B[j + l][i + k] = A[i + k][j + l];
                    }
                }
            }
        }
    } else {
        for (i = 0; i < N; i += 16) {
            for (j = 0; j < M; j += 16) {
                for (k = i; k < i + 16 && k < N; ++k) {
                    for (l = j; l < j + 16 && l < M; ++l) {
                        B[l][k] = A[k][l];
                    }
                }
            }
        }
    }
}

void registerFunctions() {
    registerTransFunction(transposesubmit, transposesubmit_desc);
}
