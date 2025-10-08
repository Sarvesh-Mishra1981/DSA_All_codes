/*
Same idea but here isSafe function will be having more cases
*/
#include<iostream>
#include<vector>
using namespace std;
bool IsSafe(vector<vector<int>>& res,int row,int col,int n){
    for(int i=0;i<col;i++){
        if(res[row][i]==1) return false;//here we are just moving the back value like sirf col tak travel kar rahe hai kyuki vo hi fill hongi and uske baad ke sab 0 honge so before ka hi check karna hai in all the path
    }
      for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (res[i][j] == 1)
            return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (res[i][j] == 1)
            return false;

    return true;
}
bool NQueen_rec(vector<vector<int>>& a,int col,int n){
    if(col==n) {
        return true;
    }
    for(int i=0;i<n;i++){
        if(IsSafe(a,i,col,n)){
            a[i][col]=1;
            if(NQueen_rec(a,col+1,n)) return true;
            a[i][col]=0;
        }
    }
    return false;
}
bool NQueen(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    if (!NQueen_rec(res, 0, n)) {
        cout << "No solution exists for " << n << " queens." << endl;
        return false;
    } else {
        cout << "Solution for " << n << " queens:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }
}
int main() {
    NQueen(4);  // classic 4x4 case
    NQueen(5);  // 5x5 case
    NQueen(6);  // 6x6 case
    NQueen(8);  // 8x8 chessboard
}
