/*
In this you will be given n cuboids and then you can rotate in any direction and then you need to stack one another only 
when back one is larger and then you need to maximise the height of the stack

so we will us the idea of the following steps
1.sort all the cubeoids as we need the height to be max and then we will sort and make the height as the max side for each cudeoids
2. sort the cubeiods on the basis of the width 
3. same thing as russian dolls that we will include or exclude and through some condition
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// check if cube 'a' can be placed on cube 'b'
bool check(vector<int>& a, vector<int>& b){
    if(a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2]) return true;
    else return false;
}

// recursive function to find maximum stack height
int StackingCube(vector<vector<int>>& cube, int curr, int prev){
    if(curr == cube.size()) return 0;
    int take = 0;
    if(prev == -1 || check(cube[curr], cube[prev])){
        take = cube[curr][2] + StackingCube(cube, curr+1, curr);
    }
    int nottake = StackingCube(cube, curr+1, prev);
    return max(take, nottake);
}

int solve(vector<vector<int>>& cube){
   // rotate cuboids so that height is max side
   for(int i = 0; i < cube.size(); i++){
       sort(cube[i].begin(), cube[i].end());
   }
   
   // sort cuboids by base area (width * length) descending
   sort(cube.begin(), cube.end(), [](const vector<int>& a, const vector<int>& b){
       return (a[0] * a[1]) > (b[0] * b[1]);
   });

   return StackingCube(cube, 0, -1);
}

int main(){
    vector<vector<int>> cube = {
        {4, 6, 7},
        {1, 2, 3},
        {4, 5, 6},
        {10, 12, 32}
    };
    
    int maxHeight = solve(cube);
    cout << "Maximum stack height: " << maxHeight << endl;
    
    return 0;
}
