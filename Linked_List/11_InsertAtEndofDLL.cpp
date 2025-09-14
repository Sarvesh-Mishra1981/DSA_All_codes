#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int x){
        val=x;
        next=NULL;
        prev=NULL;
    }
};
void TraverseLL(Node* head){
    if(head==NULL) return;
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}
Node* InsertAtEnd(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL) return temp;
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
int main(){
    Node* head= new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    Node* temp3=new Node(40);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp2->next=temp3;
    temp3->prev=temp2;
    Node* head2=InsertAtEnd(head,50);
     TraverseLL(head2);
    return 0;
}