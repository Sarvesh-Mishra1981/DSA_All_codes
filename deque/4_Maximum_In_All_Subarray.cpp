#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void MaxInSubarray(vector<int>& v,int k){
    /*
    the basic idea is that we will allow to store the min ele at the end and then we will just return the first element and 
    we will remove the element that are old 
    */
    deque<int> dq;
    for(int i=0;i<k;i++){//building the first k deque;
        while(!dq.empty() && v[i]>=v[dq.back()]){
            dq.pop_back();//we allowed only the smalleer elements at the end hence the max will be at the front ;
        }
        dq.push_back(i);
    }
    for(int i=k;i<v.size();i++){
        cout<<v[dq.front()]<<" ";
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();//just delete the elements that are samller
        }
        while(!dq.empty() && v[i]>=v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
}
int main(){
vector<int> a{1,3,5,4,2,6,9,5,3,7};
MaxInSubarray(a,3);
}