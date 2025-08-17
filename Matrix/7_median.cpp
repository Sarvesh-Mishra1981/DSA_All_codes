#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int matMed(vector<vector<int>>& mat, int r, int c) {
    int minVal = mat[0][0], maxVal = mat[0][c-1];
    
    for(int i=1; i<r; i++) {
        if(mat[i][0] < minVal) minVal = mat[i][0];
        if(mat[i][c-1] > maxVal) maxVal = mat[i][c-1];
    }

    int medPos = (r * c + 1) / 2;

    while(minVal < maxVal) {
        int mid = (minVal + maxVal) / 2;
        int midPos = 0;

        for(int i=0; i<r; i++)
            midPos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();

        if(midPos < medPos)
            minVal = mid + 1;
        else
            maxVal = mid;
    }
    return minVal;
}

int main(){
    return 0;
}