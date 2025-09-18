#include<iostream>
#include<stack>
using namespace std;
//this is stck stl-:
/*
- **empty()** – Returns whether the stack is empty.
- **size()** – Returns the size of the stack.
- **top()** – Returns a reference to the topmost element of the stack.
- **push(g)** – Adds the element ‘g’ at the top of the stack.
- **pop()** – Deletes the topmost element of the stack.
All the above Stack operations including push(), pop(), empty(), size(), top() have O(1) time complexity. **How do they work internally**??

Stack data structure can be implemented on top of any data structure that provide following operations:

back(), size(), empty(), push_back(), pop_back(). The three container which provide all these functionalities are List, 
deque and Vector, So stack container can be implemented using any of these three containers. 
By default it is implemented using deque container.

Since stack is implemented using other containers and acts as an interface, it is also known as the C**ontainer Adapter 
(**which is a term in STL Language **).** Other examples of container adapters can be queue and priority queue.
 ****All the operations like back(), size(), empty(), push_back(), pop_back() are implemented in O(1) time, 
So stack is guarenteed to take O(1) time complexity for all such operations.

*/
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
}