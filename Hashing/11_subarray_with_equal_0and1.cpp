/* 
the idea is that what we will do is that we will just convert all the zeros into -1 and then i will just find the longest subarary with zero sum

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void convertZeroToMinusOne(vector<int>& a){
    for(int i=0;i<a.size();i++){
        if(a[i]==0) {
            a[i]=-1;
        }
    }
}
int longest_sunarray(vector<int>& a){
    int n=a.size();
    unordered_map<int,int> m;
    convertZeroToMinusOne(a);
    int pre_sum=-1;
    int res=0;
    for(int i=0;i<n;i++){
        pre_sum+=a[i];
        if(pre_sum==0) {
            res=max(res,i+1);
        }
        if(m.find(pre_sum)==m.end()){
            m.insert({a[pre_sum],i});
        }
        if(m.find(pre_sum)!=m.end()){
            res=max(res,i-m[a[pre_sum]]);
        }
    }
return res-1;
}
int main(){
    vector<int> a={1,0,1,0,1,0,1,0,1,1,1,1};
    cout<<longest_sunarray(a);
    return 0;

}