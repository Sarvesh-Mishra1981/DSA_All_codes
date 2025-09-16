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
Node* MergeSortedLL(Node* a,Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node* head=NULL,*tail=NULL;
    if(a->val>b->val){
        head=b;
        tail=b;
        b=b->next;
    }
    else{
        head=a;
        tail=a;
        a=a->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->val<=b->val){
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else{
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    if(a==NULL) tail->next=b;
    else tail->next=a;
    return head;
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

    Node* head2 = new Node(5);
    Node* temp5 = new Node(15);
    Node* temp6 = new Node(25);
    Node* temp7 = new Node(35);
    Node* temp8 = new Node(45);

    head2->next = temp5;
    head2->next->next = temp6;
    head2->next->next->next = temp7;
    head2->next->next->next->next = temp8;

   Node* head3= MergeSortedLL(head,head2);
   TraverseLL(head3);

return 0;

}