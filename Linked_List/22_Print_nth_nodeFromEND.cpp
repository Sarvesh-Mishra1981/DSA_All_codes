#include<iostream>
using namespace std;
//to find the nth node from the end we will move the fast pointer n ahead and then we move slow and fast by one each;
class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }    
};
int MiddleofLL(Node* head){
    if(head==NULL) return -1;

   Node* slow=head;
   Node* fast=head;
    while(fast!=NULL &&  fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->val;
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    Node* temp3=new Node(40);
    head->next=temp;
    head->next->next=temp2;
    head->next->next->next=temp3;
cout<<MiddleofLL(head);


return 0;

}