//the idea is that we we will find the next smaller and previous smaller element and then suntarct the both distance and then multiply the a[i] and that will b ethe answer;
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int>& a, int n) {
    stack<int> s;
    vector<int> prev(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        prev[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return prev;
}

vector<int> nextSmaller(vector<int>& a, int n) {
    stack<int> s;
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        next[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return next;
}

int LargestRectangularArea(vector<int>& a) {
    int n = a.size();
    vector<int> prev = prevSmaller(a, n);
    vector<int> next = nextSmaller(a, n);
    int res = 0;

    for (int i = 0; i < n; i++) {
        int width = next[i] - prev[i] - 1;   
        int curr = width * a[i];
        res = max(res, curr);
    }
    return res;
}

int main() {
    vector<int> a{6, 2, 4, 5, 1, 5, 6};
    cout << LargestRectangularArea(a);
    return 0;
}