//
//  definitions.cpp
//  Sudoko
//
//  Created by John Ayman on 13/09/2022.
//
#include <iostream>
#include "sudoku.h"

using namespace std;

void print_notes()
{
    cout<<"WELCOME TO SUDOKU SOLVER!"<<endl<<endl;
    cout<<"NOTES"<<endl;
    cout<<"Enter the numbers in order (fill the first row then the second , ...ect) "<<endl;
    cout<<"For empty boxes enter '0' "<<endl;
}
//print the grid
void print_grid(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
}

//Checks whether it will be legal to assign num to the given row, col
bool isSafe(int grid[N][N], int row, int col, int num)
{
    //if we find the same number in the same row we reuturn false
    for (int i=0; i<=8; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    
    
    //if we find the same number in the same column we reuturn false
    for (int i=0; i<=8; i++)
    {
        if (grid[i][col]==num)
        {
            return false;
        }
    }
    
    
   //if we find the same number in the 3*3 particular grid we return false
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }
    
    
    return true;
}


bool solveSudoku(int grid[N][N], int row, int col)
{
    //Check if we have reached the 8th row and 9th column
    if (row == N - 1 && col == N)
    {
        return true;
    }
    
    
    
    // Check if column value becomes 9 , we move to next row and column start from 0
    if (col == N)
        {
            row++;
            col = 0;
        }
    
    // Check if the current position of the grid already contains value >0, we iterate for next column
    if (grid[row][col] > 0)
          {
              return solveSudoku(grid, row, col + 1);
          }
    
    
    
    for (int i = 1; i <= N; i++)
        {
             
            // Check if it is safe to place the num (1-9)  in the given row ,col  then we move to next column
            if (isSafe(grid, row, col, i))
            {
                grid[row][col] = i;
               
                //  Checking for next possibility with next column
                if (solveSudoku(grid, row, col + 1))
                    return true;
            }

                grid[row][col] = 0;
            
            
        }
    
    return false;
}
