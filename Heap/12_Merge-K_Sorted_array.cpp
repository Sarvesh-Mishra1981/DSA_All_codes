#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Triplet {
public:
    int val, aPos, iPos;
    Triplet(int a, int b, int c) {
        val = a;
        aPos = b;
        iPos = c;
    }
};
class Mycmp {
public:
    bool operator()(Triplet &a, Triplet &b) {
        return a.val > b.val;  
    }
};

vector<int> Mergearray(vector<vector<int>>& arr, int k) {
    vector<int> res;
    priority_queue<Triplet, vector<Triplet>, Mycmp> pq;
    for (int i = 0; i < k; i++) {
        if (!arr[i].empty()) {
            Triplet t(arr[i][0], i, 0);
            pq.push(t);
        }
    }
    while (!pq.empty()) {
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);

        int ap = curr.aPos;
        int ip = curr.iPos;
        if (ip + 1 < arr[ap].size()) {
            Triplet t(arr[ap][ip + 1], ap, ip + 1);
            pq.push(t);
        }
    }

    return res;
}

int main() {
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = arr.size();

    vector<int> result = Mergearray(arr, k);

    cout << "Merged array: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
