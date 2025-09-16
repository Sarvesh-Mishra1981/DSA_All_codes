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
//the idea is that we make the length of the ll and then we move the larger ll to the (maxlen-minlen) and then we move each pointer by one and when we get common node we return it
void TraverseLL(Node* head){
    if(head==NULL) return;
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->val<<"->";
        curr=curr->next;
    }
    cout<<"NULL"<<endl;
}
 int getLength(Node* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
Node* Intersection(Node* head,Node* head2){
    int len1=getLength(head);
    int len2=getLength(head2);
    while(len1>len2){
        head=head->next;
        len1--;
    }
     while(len2>len1){
        head2=head2->next;
        len2--;
    }
    while(head && head2){
        head=head->next;
        head2=head2->next;
        if(head==head2) return head;
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
    temp4->next=temp;
Node* head3=Intersection(head,temp4);
TraverseLL(head3);



return 0;

}