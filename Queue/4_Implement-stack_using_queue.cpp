#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q1, q2;

    bool isEmpty() {
        return q1.empty();
    }

    int sizeOf() {
        return q1.size();
    }

    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  
    cout << "Popped: " << st.pop() << endl;      
    cout << "Top element: " << st.top() << endl;  
    cout << "Stack size: " << st.sizeOf() << endl; 

    return 0;
}
