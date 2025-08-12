#include<iostream>
#include<vector>
using namespace std;
void Sort_it(vector<int>& a){
int n=a.size();
int i=-1;
int j=n;
while(true){
    do{i++;} while(a[i]<a[0]);
    do{j--;} while(a[j]>a[0]);
    if(i>=j) return;
    swap(a[i],a[j]);
}
}
int main() {
    vector<int> a = {3, 4, 6, 9, 2, 1};
    Sort_it(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}
