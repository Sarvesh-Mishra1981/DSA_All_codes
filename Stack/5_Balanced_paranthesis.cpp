#include<iostream>
#include<stack>
using namespace std;

bool matching(char a, char b) {
    return ((a=='(' && b==')') ||
            (a=='[' && b==']') ||
            (a=='{' && b=='}'));
}

bool balancedParanthesis(string& s) {
    stack<char> b; 
    int n = s.length();
    for(int i=0; i<n; i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            b.push(s[i]);
        }
        else {
            if(b.empty()) return false;
            else if(matching(b.top(), s[i]) == false) { 
                return false;
            }
            else b.pop();
        }
    }
    return b.empty();
}

int main() {
    string s = "{([()])}";
    string b = "{([(])}";

    cout << balancedParanthesis(s) << endl; 
    cout << balancedParanthesis(b) << endl;

    return 0;
}
