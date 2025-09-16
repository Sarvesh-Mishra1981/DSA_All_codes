#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

void TraverseLL(Node* head) {
    if (head == NULL) return;
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

Node* RemoveDublicates(Node* head) {
    Node* curr = head;
    if (curr == NULL || curr->next == NULL) return head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(30);
    Node* temp4 = new Node(40);

    head->next = temp;
    head->next->next = temp2;
    head->next->next->next = temp3;
    head->next->next->next->next = temp4;

    Node* head2 = RemoveDublicates(head);
    TraverseLL(head2);

    return 0;
}
