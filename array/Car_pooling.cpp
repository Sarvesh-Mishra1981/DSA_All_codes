#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> events;
        
        for (auto& t : trips) {
            events.push_back({t[1], t[0]});  
     events.push_back({t[2], -t[0]});  
        }
        sort(events.begin(), events.end());  
        int curr = 0;
        for (auto& e : events) {
            curr += e.second;
   if (curr > capacity) return false;
        }
        return true;
    }
};
// here u need to check for range like v range of car mantai karni thi vo merese nahi hui thi ,,so kya kiya ki pairt bana kar usme 
//daal diya start distance and kitne log chadenge and end distance  par negative to kitne log chadhe hai 
//and add karte jaenge leetcode -carr polling 