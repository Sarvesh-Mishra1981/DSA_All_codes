//In the circular linked List.. the last componenet is connected to the 1st one.
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }    
};
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
    temp2->next=head;

return 0;

}