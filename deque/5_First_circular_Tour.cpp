#include<iostream>
#include<vector>
using namespace std;
/*
the basic that is used here is that if we get petrol negative at any i point then from 0 to i point no answer can exist 
and hence we start from i+1;
*/
int Petrol(vector<int>& a,vector<int>& b){
    int start=0; int curr=0; int prev=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        curr+=(a[i]-b[i]);
        if(curr<0) {
            start=i+1;
            prev=curr;
        curr=0;  }
    }
    return ((curr+prev>=0)?start+1:-1);
}
int main(){
vector<int> petrol{50,10,60,100};
vector<int> dis{30,20,100,10};
cout<<Petrol(petrol,dis);
return 0;
}