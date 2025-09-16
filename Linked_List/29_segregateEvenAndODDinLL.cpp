#include<iostream>
#include<unordered_set>
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
Node* segregate(Node* head){
    Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    for(Node* curr=head;curr!=NULL;curr=curr->next){
        int x=curr->val;
        if(x%2==0){
            if(es==NULL){
                es=curr;
                ee=curr;
            }
            else {
                ee->next=curr;
                ee=ee->next;
            }
        } else{
            if(os==NULL){
                os=curr;
                oe=curr;
            }
            else {
                oe->next=curr;
                oe=oe->next;
            }
        }
    }
    return es;

}
int main(){
      Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(30);
    Node* temp4 = new Node(40);

    head->next = temp;
    head->next->next = temp2;
    head->next->next->next = temp3;
    head->next->next->next->next = temp4;
    temp4->next=temp2;

   Node* evenodd= segregate(head);
   TraverseLL(evenodd);

return 0;

}