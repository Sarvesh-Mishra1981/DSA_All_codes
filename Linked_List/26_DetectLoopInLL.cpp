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
bool DetectLoop(Node* head){
    unordered_set<Node*> s;
    for(Node* curr=head;curr!=NULL; curr=curr->next){
        if(s.find(curr)!=s.end()){
            return true;
        }
        s.insert(curr);
    }
    return false;
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

    cout<<DetectLoop(head);

return 0;

}