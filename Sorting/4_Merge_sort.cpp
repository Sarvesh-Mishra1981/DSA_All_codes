#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int low, int mid, int high) {
    int l = mid - low + 1;
    int h = high - mid;

    vector<int> left(l);
    vector<int> right(h);

    for (int i = 0; i < l; i++) {
        left[i] = a[low + i];
    }
    for (int i = 0; i < h; i++) {
        right[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;
    while (i < l && j < h) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < l) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < h) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& a, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    vector<int> a = {3, 4, 6, 9, 2, 1};
    mergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}
