#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Intersection(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int m = a.size();
    int n = b.size();
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i - 1]) {
            i++;
            continue;
        }

        if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 5};
    Intersection(a, b);
    return 0;
}
