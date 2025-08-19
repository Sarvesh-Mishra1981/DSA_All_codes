#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/* the basic idea is that first we find the element that has no element before it 
then what we do is that we find the next consecute and till we get it then we just increament the count

*/
int longest_subseq(vector<int>& a) {
    if(a.empty()) return 0;  
    unordered_set<int> m(a.begin(), a.end());
    int res = 1;

    for(int x : m) {
        if(m.find(x-1) == m.end()) {
            int curr = x;
            int count = 1;
            while(m.find(curr+1) != m.end()) {
                curr++;
                count++;
            }
            res = max(res, count);
        }
    }
    return res;
}

int main() {
    vector<int> a = {1,2,3,5,6,9};
    cout << longest_subseq(a); 
    return 0;
}
