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
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}
Node* SortedInsert(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL) return temp;
    if(x<head->val){ 
        temp->next=head;
        return temp;}
        Node* curr=head;
    while(curr->next!=NULL && curr->next->val<x){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
Node* head2=SortedInsert(head,25);
TraverseLL(head2);

return 0;

}