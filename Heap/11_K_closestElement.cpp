#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Mypair {
public:
    int diff;  
    int val;  
    Mypair(int d, int v) {
        diff = d;
        val = v;
    }
};

struct cmp {
    bool operator()(Mypair &a, Mypair &b) {
        return a.diff < b.diff; 
    }
};

void K_closest_element(vector<int>& a, int k, int x) {
    priority_queue<Mypair, vector<Mypair>, cmp> pq;
    for (int i = 0; i < k; i++) {
        pq.push(Mypair(abs(a[i] - x), a[i]));
    }

    for (int i = k; i < a.size(); i++) {
        int diff = abs(a[i] - x);
        if (diff < pq.top().diff) {  
            pq.pop();
            pq.push(Mypair(diff, a[i]));
        }
    }
    while (!pq.empty()) {
        cout << pq.top().val << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3, x = 7;

    K_closest_element(arr, k, x);

    return 0;
}
