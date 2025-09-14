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
int searchLL(Node* head,int x){
    if(head==NULL) return -1;
    if(head->val==x) return 1;

    else {
        int res=searchLL(head->next,x);
        if(res==-1) return -1;
        else return (res+1);
    }
}
int main(){
     Node* head=new Node(10);
    Node* temp=new Node(20);
    Node* temp2=new Node(30);
    head->next=temp;
    head->next->next=temp2;
int pos=searchLL(head,20);
cout<<pos<<endl;
return 0;

}