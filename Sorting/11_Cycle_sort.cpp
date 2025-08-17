#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0;i<n;i++){
        int item=arr[i];
        int pos=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>item) pos++;
        }
        swap(item,arr[pos]);

        while(pos!=i){//this is because the when we interchange the num then the num is disturbed hence we recover that using this while loop
            int pos=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>item) pos++;
        }
        swap(item,arr[pos]);
        }
    }
}

int main() {
    vector<int> arr = {20, 40, 50, 10, 30};
    cycleSort(arr);
    for (int num : arr) cout << num << " ";
}
//O(n²) time, O(1) space).