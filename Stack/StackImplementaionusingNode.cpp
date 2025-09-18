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
class Stack{
    public:
    Node* head;
    int size;
    Stack(){
        size=0;
        head=NULL;
    }
    void push(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop(){
        if(head==NULL || head->next==NULL) return;
        Node* temp=head;
        int val=head->val;
        head=head->next;
        delete(temp);
        size--;
    }
    bool Isempty(){
        if(head==NULL) return true;
        else return false;
    }
    int sizeOf(){
        return size;
    }
    int peek(){
        return head->val;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
	Stack s;

	// Push the elements of stack
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);

	// Display stack elements
	s.display();

	// Print top element of stack
	cout << "\nTop element is " << s.peek() << endl;
	s.pop();
	s.pop();
	s.display();

	cout << "\nTop element is " << s.peek() << endl;

	return 0;
}