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
Node* DeleteAtBeggining(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    //the basic idea is that we make the 1st element a ssame as the first element and then we will delete the 1st element;
    head->val=head->next->val;
    Node* temp=head->next;
    head->next=temp->next;
    delete(temp);
    return head;
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
    temp2->next=head;
    Node* head2=DeleteAtBeggining(head);
    traverseCircular(head2);

return 0;

}