//
//  sudoko_h.h
//  Sudoko
//
//  Created by John Ayman on 13/09/2022.
//
#include <iostream>

const int N =9;
void print_notes();
void print_grid(int arr[N][N]);
bool isSafe(int grid[N][N], int row, int col, int num);
bool solveSudoku(int grid[N][N], int row, int col);
