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
void TraverseLL(Node* head){
    if(head==NULL) return;
        cout<<head->val<<"->";
        TraverseLL(head->next);
    cout<<endl;
}
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
TraverseLL(head);
TraverseLL(head2);
return 0;
}