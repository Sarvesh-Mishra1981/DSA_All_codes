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

int maxRectangle(vector<vector<int>>& a) {
    int res = LargestRectangularArea(a[0]);   // Base case for first row
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 1) {
                a[i][j] += a[i-1][j];        // Update histogram
            }
        }
        res = max(res, LargestRectangularArea(a[i]));
    }
    return res;
}

int main() {
    vector<vector<int>> a{
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1}
    };
    cout << maxRectangle(a);
    return 0;
}
