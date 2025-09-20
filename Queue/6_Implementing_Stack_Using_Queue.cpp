#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> s1, s2;

    bool isEmpty() {
        return s1.empty();
    }

    void enqueue(int x) {
        s2.push(x);
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s1.top();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; 
    cout << "Popped: " << q.pop() << endl;        
    cout << "Front element: " << q.front() << endl; 

    q.enqueue(40);
    cout << "Popped: " << q.pop() << endl;        
    cout << "Popped: " << q.pop() << endl;    
    cout << "Popped: " << q.pop() << endl;        
    cout << "Popped: " << q.pop() << endl;         

    return 0;
}
