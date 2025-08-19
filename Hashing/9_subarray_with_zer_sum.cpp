/* so the idea is ki ek subarray zero sum tab hi form kar sakta hia jab vo presum is equal to zero or 
consder that sum of the 0->ai is sum2 and 0->af where f<i then if they are equal then the from af->ai the subarray sum is zero*/
//using this idea there are hence only 2 cases for the sum to be  zero
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool issumzero(vector<int>& a){
    unordered_set<int> m;
    int pre_sum=0;
    for(int i=0;i<a.size();i++){
        pre_sum+=a[i];
        if(pre_sum==0) return true;
        if(m.find(pre_sum)!=m.end()) return true;
        m.insert(pre_sum);
    }
    return false;
}
int main(){
    vector<int> a={1,2,3,-3,5};
    cout<<issumzero(a);
    return 0;
}