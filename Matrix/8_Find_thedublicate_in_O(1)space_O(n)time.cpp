//this is very important and this algo we will not use any hash map or set and single for loop
//inspired fromthe leetcode 442 -
/*
dekh isme hame elemnets diye hai from 1 to n so agar if we have 2 then uski pos index 1 hogi so iski ko ham use kar rahe hai

what we do is that if we get i element then then ham kya krenge ki i-1 ka elemnt kjo negative kar denge 
so ye hamre pass refrence hoga ki ye visited hai 
and if conditon me ham likhenge ki if thta index negative hua to vo repeated hai 
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> finddublicate(vector<int>& a){
    vector<int> res;
    for(int i=0;i<a.size();i++){
        int idx=abs(a[i])-1;
        if(a[idx]<0){
            res.push_back(a[i]);
        }
        else{
            a[idx]=-a[idx];
        }
    }
    return res;
}



int main(){
    vector<int> a={1,2,3,5,67,7,7};
    vector<int> ans=finddublicate(a);
    return 0;
}

// there is different methord also using that of the linked list slow and fast approch 
/* 
so usme kya hita hai ki hame phele slow and fast ko karte hai and ek baar dono match hogye then slow ko 0 karte hai and fast ko fast hi rehne dete hai 
so if baad me jaha mile vo repeted hai 
Algorithm (Floyd’s Tortoise and Hare)

Think of the array as a linked list:

Each index points to nums[index].

Because of the duplicate, there must be a cycle in this "linked list".

Phase 1: Detect cycle

Use two pointers:

slow = nums[slow] (1 step at a time)

fast = nums[nums[fast]] (2 steps at a time)

They will eventually meet inside the cycle.

Phase 2: Find entrance of cycle (duplicate number)

Reset one pointer to start (slow = nums[0])

Move both one step at a time (slow = nums[slow], fast = nums[fast])

Where they meet = duplicate number.



*/