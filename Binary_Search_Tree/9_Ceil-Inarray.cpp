/*
In this we will be using the idea of the set data structure and 

so set is basically sam eas that of the unordered_set and it stroes unique elements int increasing order and it is based on the RedBlack Tree
The time complexity of the set is all the operation insert delete and find is O(logn)

u can ascess the first element as *s.begin() and the last element as *s.rbegin()
Ad rest of the function is same as that of the unordered set and it has function called as the 

upper_bound--- it returns the iterator that is strictly greater than that element 
lower_bound---- it return the iterator of the element that is equal or smaller than that element


So in we will use the idea of the lower bound and use the set in this and find the ceil that is the greater elemnet
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
void CeilIn_Left(vector<int>& a){
    set<int> s;
    s.insert(a[0]);
    cout<<-1<<" ";
    for(int i=1;i<a.size();i++){
        if(s.lower_bound(a[i])!=s.end()){
            auto it=s.lower_bound(a[i]);
            cout<<*it<<" ";
        }
        else {
            cout<<-1<<" ";
        }
        s.insert(a[i]);
    }

}
int main(){
    vector<int> a={2,8,30,15,25,12};
    CeilIn_Left(a);
}