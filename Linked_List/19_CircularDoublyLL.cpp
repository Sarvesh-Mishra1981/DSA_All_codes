#include<iostream>
using namespace std;
class Node{
 int val;
 Node* next;
 Node* prev;
 Node(int x){
    val=x;
    next=NULL;
    prev=NULL;
 }
};