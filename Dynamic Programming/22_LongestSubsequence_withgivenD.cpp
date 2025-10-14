/*
here u will be given diffence and the array and u need to find the longest subsequence with given sum
so what we will do is that we will make unordered_map and in that map we will find the diff and 
upadte the ocuurence of the digit and find the max difference 

*/
#include<vector>
#include<iostream>
using namespace std;
int LongestSubseq(vector<int>& a,int d){
    unordered_map<int,int> m;
    int ans=INT_MIN;
    for(int i=0;i<a.size();i++){
        int diff=a[i]-d;
        int temp=0;
        if(m.count(diff)){
            temp=m[diff];
        }
        m[a[i]]=1+temp;
        ans=max(ans,temp);
    }
    return ans;
}
int main() {
    vector<int> a = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int d = -2;

    cout << "Longest subsequence with difference " << d << " = " 
         << LongestSubseq(a, d) << endl;

    return 0;
}