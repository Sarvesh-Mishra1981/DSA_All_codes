//this is the basic struvture of the Linked List
#include<iostream>
class Node {
public:       
    int x;
    Node* next;

    Node(int val) {
        x = val;
        next = NULL;
    }
};
int main(){
    Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;

    Node* head2 = new Node(1);
head2->next = new Node(2);
head2->next->next = new Node(3);
head2->next->next->next = new Node(4);
head2->next->next->next->next = new Node(5);

    return 0;
}
