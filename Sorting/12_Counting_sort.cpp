#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int n=arr.size();
    //so the basic idea is that we caluclute the number of that element in there and the again claculte the num of the 
    //elemnts that are cumulative of it then we just place them 
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Step 2: Count array
    vector<int> count(range, 0);
    for (int num : arr)
        count[num - minVal]++;

    // Step 3: Cumulative count
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Step 4: Output array (stable sort)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Step 5: Copy back
    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    for (int num : arr) cout << num << " ";
}
//O(n + k) time, O(k) space