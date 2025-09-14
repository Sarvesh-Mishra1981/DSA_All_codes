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
Node* DeleteAtBeggining(Node* head){
Node* temp=head->next;
delete(head);
return temp;
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
Node* head2=DeleteAtBeggining(head);
TraverseLL(head2);

return 0;

}