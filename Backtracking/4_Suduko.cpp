/*
In the we check the for every value of the 1 to 9 using the for loop and then there is Issafe function and in that function
we need to check the horizontal as well as the vertical and the grid of it and rest of the implementation is same in this we 
in every call check for the zero 
*/
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
bool isSafe(vector<vector<int>>& grid,int row,int col,int x){
    // checking the horizontal and the vertical
    int n=grid.size();
    for(int i=0;i<n;i++){
        if(grid[i][col]==x || grid[row][i]==x) return false;
    }
    //Now checking for the grid so for the grid what we will do is that we will find the end point for the grid for
    // that we will use the centre as the refrence point.
   int s = sqrt(n);
    int a = row - row % s;
    int b = col - col % s;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (grid[a + i][b + j] == x)
                return false;
        }
    }
    return true;
}
bool solve_rec(vector<vector<int>>& grid){
    //this is now done to find the zero in every call
      int n = grid.size();
    int row = -1, col = -1;
    bool found = false;

    // Find the first empty cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    // Base case — no empty cell found
    if (!found)
        return true;
    for(int x=1;x<=9;x++){
    if(isSafe(grid,row,col,x)){
        grid[row][col]=x;
        if(solve_rec(grid)) return true;
        grid[row][col]=0;
    }
    }
    return false;
}
bool solve(vector<vector<int>>& grid){
    int n=grid.size();
    if(!solve_rec(grid)) return false;
     cout << "Solved Sudoku:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return true;
}
int main(){
vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (!solve(grid))
        cout << "No solution exists.\n";

    return 0;
}