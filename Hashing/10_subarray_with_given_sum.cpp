/* the idea is same as that of the pair with the zero sum. The subarray can have the sum as sum when
1. the pre_sum has the same sum as that of the target
2. when the pre_sum-target has the val in the unordered map then we will just make the max val as the output */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int issumTarget(vector<int>& a, int Target) {
    int n = a.size();
    unordered_map<int,int> m;
    int res = 0, pre_sum = 0;

    for (int i = 0; i < n; i++) {
        pre_sum += a[i];
        if (pre_sum == Target) res = max(res, i + 1);
        if (m.find(pre_sum - Target) != m.end()) res = max(res, i - m[pre_sum - Target]);
        if (m.find(pre_sum) == m.end()) m[pre_sum] = i;
    }
    return res;
}

int main() {
    vector<int> a = {1,2,3,4,5,5};
    int res = issumTarget(a, 6);
    cout << res;
    return 0;
}
