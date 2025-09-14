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
Node* InsertAtend(Node* head,int val){
    if(head==NULL) return head;
Node* temp=new Node(val);
Node* curr=head;
while(curr->next!=NULL){
curr=curr->next;
}
curr->next=temp;
return head;
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
Node* head2=InsertAtend(head,40);
TraverseLL(head2);

return 0;

}