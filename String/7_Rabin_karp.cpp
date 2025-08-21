/*
The idea of the Rabin karp is that first we willcompare the hasf of that elemnts if the hash value is same 
then we will cmpare the indivisual elemnts and to store the hash value we use the idea of the rolling hash

*/

#include <iostream>
#include <string>
using namespace std;

bool Rabin_karp(string& a, string& b) {
    int n = a.length();
    int m = b.length();
    int d = 256;
    int q = 101;
    int h = 1;

    for (int i = 1; i <= m - 1; i++) {
        h = (h * d) % q;// this the has value of the 1st element hash multiple this will be used in the rolling hash
    }

    int h1 = 0, h2 = 0;
    for (int i = 0; i < m; i++) {
        h1 = (h1 * d + b[i]) % q;
        h2 = (h2 * d + a[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (h1 == h2) {//we compare the indivisual element
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
// now we compute the rolling hash
        if (i < n - m) {
            h2 = (d * (h2 - a[i] * h) + a[i + m]) % q;
            if (h2 < 0) h2 += q;// this line is written so that h1 donot go in the negative values;
        }
    }
    return false;
}

int main() {
    string a = "abcdef";
    string b = "cde";
    if (Rabin_karp(a, b)) cout << "yes";
    else cout << "no";
}
