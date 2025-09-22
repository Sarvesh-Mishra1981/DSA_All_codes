#include<iostream>
#include<deque>
using namespace std;
class Mydsg{
public:
    deque<int> dq;
    void insert_max(int x){
        dq.push_back(x);
    }
    void insert_min(int x){
        dq.push_front(x);
    }
    int get_max(){
        return dq.back();
    }
    int get_min(){
        return dq.front();
    }
    void  extract_min(){
        dq.pop_front();
    }
    void extract_max(){
        dq.pop_back();
    }

    void display() {
        for (int x : dq) cout << x << " ";
        cout << endl;
    }
};
int main() {
    Mydsg ds;
    ds.insert_max(10);
    ds.insert_min(5);
    ds.insert_max(20);
    ds.insert_min(2);

    cout << "Deque after insertions: ";
    ds.display();
    cout << "Minimum element: " << ds.get_min() << endl;
    cout << "Maximum element: " << ds.get_max() << endl;
    ds.extract_min();
    ds.extract_max();

    cout << "Deque after extracting min and max: ";
    ds.display();

    return 0;
}