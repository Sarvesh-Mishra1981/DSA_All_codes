/*
In this you need to make word1 equal to word2 u can do any of 3 operation
1.you can delete from word1
2.insert new element
3.replace element
each has cost of 1 and you need to return the min cost to make that element same


So the basic idea is that if 2 digits are same. then we will move both forward
if not same-:
    then we will make 3 condition 1. by insert,delete and replace and then min will be returned

    and if "i" == n then we will return the diffof i and word2.length() becoz we have to add that nums
    and if "j"==n then we will return the diff of j and word1.lenght as we need to delete that nums
*/
#include<vector>
#include<iostream>
using namespace std;
int editDis(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
    if(i==word1.length()) return (word2.length()-i);
    if(j==word2.length()) return (word1.length()-j);
    int ans=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(word1[i]==word2[j]){
        return editDis(word1,word2,i+1,j+1,dp);
    }else{
        int insert=1+editDis(word1,word2,i,j+1,dp);//in insert naya letter daal diya hai but vo i udhar hi rahega to track next letter as it becomes next letter
        int del=1+editDis(word1,word2,i+1,j,dp);// we are delete the i and moving i and checking it with j
        int replace=1+editDis(word1,word2,i+1,j+1,dp);//as new word added hence both will move froward

        ans=min(insert,min(replace,del));
    }
    dp[i][j]=ans;
    return  dp[i][j];
}
int main(){
 string word1 = "intention";
    string word2 = "execution";

    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "Minimum Edit Distance: "
         << editDis(word1, word2, 0, 0, dp) << endl;

    return 0;
}