#include<iostream>
#include<vector>
using namespace std;
int SumOF(vector<int>& a,int sum,int i){
    if(i==a.size()){
        return (sum==0?1:0);
    }
    return(SumOF(a,sum,i+1)+SumOF(a,sum-a[i],i+1));
}
int main(){
 vector<int> a = {1, 2, 3, 4};  
    int target = 5;               

    int count = SumOF(a, target, 0);

    cout << "Number of subsets with sum " << target << " = " << count << endl;

    return 0;
}