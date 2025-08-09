#include<iostream>
#include<vector>
using namespace std;
//the basic idea is that what we do is that we make bundles and bundles ke just bahar wala element ko uske phele wale se while loop me check akrte hai 
//id that element is is bigger j wala then ham j+1 ko j bana dete hai aiosa karte hai jab tak correct position nahi mil jata 
//and tu soch raha hoga ki jo final position hoga uski to value change hi nahi hui.... but ha isliye ham last me us posituion ko update kar dete hai 
void insertion_sort(vector<int>& a){
    for(int i=1;i<a.size();i++){
        int key=a[i];
        int j=i-1;//the start of the sorted bundle
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;// j+1 isliye kyuki last me vo ek extra check karega isliye 
    }

}

int main(){
    vector<int> a={3,4,6,9,2,1};
    insertion_sort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
}