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
void DetectRemoveLoop(Node* head){
   //the idea is that we use slow and fast node and then if they meet then there is loop and then we place the slow at the start and then move both slow and fast by each one step
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return;
    slow=head;
    if(slow==fast){
         while(fast->next!=slow){
                fast=fast->next;
        }
    } else {
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    
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

    DetectRemoveLoop(head);

return 0;

}