#include<iostream>
#include<vector>
using namespace std;
//like bubble sort what we do is that like bubbl sort we find the smallest element but not by just comapring the j and j+1
//we fix the first element and then traverse the full array through j and then we just swap the j and i and hence then just move the i;
// in bubble sort the i is just used for the regulation the last element matlab ki aage badhnae ke liye but here it is used for the swap also;
//time complexity is 0(n^2)
void SelectionSort(vector<int>& a){
    for(int i=0;i<a.size();i++){
        int min_ind=i;
        for(int j=i+1;j<a.size();j++){
            if(a[min_ind]>a[j]){
                min_ind=j;
            }
        }
        swap(a[min_ind],a[i]);
    }


}
int main(){
    vector<int> a={3,4,6,9,2,1};
    SelectionSort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
}