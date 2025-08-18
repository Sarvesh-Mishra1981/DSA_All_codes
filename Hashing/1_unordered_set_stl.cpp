#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> m;
    m.insert(15);
    m.insert(15);
    m.insert(10);
    m.insert(14);
    m.insert(12);
    m.insert(18);
// the unordere_set is based on the hashing hence the the order will be differnt and not fixed hence for the order we should 
// set which is based on the red black tree

//so first comes the normal traversal 
for(auto it=m.begin();it!=m.end();it++){
    cout<<*it<<' ';
}
// here it is the pointer and the *it is the value of that;

//Now comes the find functio and the count function which can be used for the find the particular element and count function is used 
//to count the number of the elemnts same as thta one 

    if(m.find(12)!=m.end()) return true;

    int num=m.count(15);


//Now comes the erase function thta has 2 types one is thta you can erase from the start and till the end or you can just find the 
//num u want to dlete and then just erase it with the same operation
    m.erase(15);
    cout << m.size() << " ";
    auto it = m.find(10);
    m.erase(it);
    cout << m.size() << " ";
    return 0;


}