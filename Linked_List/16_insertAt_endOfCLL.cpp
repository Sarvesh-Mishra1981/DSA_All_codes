//In the circular linked List.. the last componenet is connected to the 1st one.
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
void traverseCircular(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head); 
    cout << endl;
}
Node* InsertAtEND(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL) return temp;
    //the basic idea is that we make the 2nd element as we have the acess of the head and then make the head->val as of x and 2nd element as head->val
    // and we will just return the second element as the head and hence it will become the 1st and one before will become the last;
    temp->next=head->next;
    head->next=temp;
    swap(head->val,temp->val);
    return temp; 
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
    temp2->next=head;
    Node* head2=InsertAtEND(head,40);
    traverseCircular(head2);

return 0;

}