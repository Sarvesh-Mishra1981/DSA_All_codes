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
Node* ReverseIt(Node* prev,Node* curr){
   if(curr==NULL) return prev;
   Node* after=curr->next;
   curr->next=prev;
    return ReverseIt(curr,after);
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
Node* head2=ReverseIt(NULL,head);
        TraverseLL(head2);

return 0;

}