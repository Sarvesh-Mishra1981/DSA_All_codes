/*
the basic idea of the binary serach tree is that on the left the element present will be smaller and that 
on the right will be greater than that of the root element

all the opreation take the time coplexity of the O(logn ) and in the worst case it takes the tim ecomplexity of
O(h) where h is the height of the treee...and based in the similar logic of the tree
*/
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    Node* left,*right;
    int val;
    Node(int c){
        val=c;
        left=NULL;
        right=NULL;
    }
};
int main(){

}