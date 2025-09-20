#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(const string& infix) {
    stack<char> st;
    for (char c : infix) {
        if(isdigit(c)){
            st.push(c);
        }
        

       
    }
}

int main() {
    string infix="10 2 4*+";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
