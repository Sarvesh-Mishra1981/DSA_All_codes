#include <iostream>
#include <vector>
using namespace std;

void cycleSort(vector<int>& arr) {
    int n = arr.size();
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
        if (pos == cycle_start)
            continue;

        while (item == arr[pos])
            pos++;
        swap(item, arr[pos]);

        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;
            while (item == arr[pos])
                pos++;
            swap(item, arr[pos]);
        }
    }
}

int main() {
    vector<int> arr = {20, 40, 50, 10, 30};
    cycleSort(arr);
    for (int num : arr) cout << num << " ";
}
//O(n²) time, O(1) space).