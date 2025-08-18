#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;
    m["gfg"]=30;
    m["sar"]=40;
    m["abc"]=45;
    m["ide"] = 30;
    m["ide"] = 30;
    m["ide"] = 30;
    m["sumit"]=50;
    // the function here are same as the in the unordered_set
    for(auto it=m.begin();it!=m.end();it++){
        cout<< it->first << " "<< it->second<<" ";
        //this is one methord to get the elemnts of it 
    }
    for(auto& it:m){
        cout<<it.first<<' '<<it.second;//this is the second methord to get the element 
    }
    //now the count is used to find the num of that element 
    int x=m.count("ide");
    cout<<x;

     m.erase("ide");
    m.erase(m.begin());
    cout << m.size() << " ";
    return 0;
}

