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
Node* pairwiseswap(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* curr = head->next->next;
    Node* prev = head;
    head = head->next;  
    head->next = prev;

    while (curr != NULL && curr->next != NULL) {
        prev->next = curr->next;
        prev = curr;

        Node* next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    prev->next = curr;
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
    temp4->next=temp;
Node* head3=pairwiseswap(head);
TraverseLL(head3);



return 0;

}