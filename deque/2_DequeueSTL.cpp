#include<iostream>
#include<deque>
using namespace std;
/*
The deque supports has ascess of both front and the end and hence it can do both the work of the queue and the stack

some of the STL are given::
deque::insert()	Inserts an element. And returns an iterator that points to the first of the newly inserted elements.
deque::rbegin()	Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).
deque::rend()	Returns a reverse iterator which points to the position before the beginning of the deque (which is considered its reverse end).
deque::cbegin()	Returns a constant iterator pointing to the first element of the container, that is, the iterator cannot be used to modify, only traverse the deque.
deque::max_size()	Returns the maximum number of elements that a deque container can hold.
deque::assign()	Assign values to the same or different deque container.
deque::resize()	Function which changes the size of the deque.
deque::push_front()	It is used to push elements into a deque from the front.
deque::push_back()	This function is used to push elements into a deque from the back.
deque::pop_front() and deque::pop_back()	pop_front() function is used to pop or remove elements from a deque from the front. pop_back() function is used to pop or remove elements from a deque from the back.
deque::front() and deque::back()	front() function is used to reference the first element of the deque container. back() function is used to reference the last element of the deque container.
deque::clear() and deque::erase()	clear() function is used to remove all the elements of the deque container, thus making its size 0. erase() function is used to remove elements from a container from the specified position or range.
deque::empty() and deque::size()	empty() function is used to check if the deque container is empty or not. size() function is used to return the size of the deque container or the number of elements in the deque container.
deque::operator= and deque::operator[]	operator= operator is used to assign new contents to the container by replacing the existing contents. operator[] operator is used to reference the element present at position given inside the operator.
deque::at() and deque::swap()	at() function is used reference the element present at the position given as the parameter to the function. swap() function is used to swap the contents of one deque with another deque of same type and size.
deque::begin() and deque::end	begin() function is used to return an iterator pointing to the first element of the deque container. end() function is used to return an iterator pointing to the last element of the deque container.
deque::emplace_front() and deque::emplace_back()	emplace_front() function is used to insert a new element into the deque container. The new element is added to the beginning of the deque. emplace_back() function is used to insert a new element into the deque container. The new element is added to the end of the deque.


the diffenece in the Emplace and the insert is that emplace cretes the new place and insert there and insert has place premade and then
it just copy the elements
*/
void TraverseDq(deque<int>& a){
    deque<int>::iterator it;
    for(it= a.begin(); it< a.end();++it ){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main(){
deque<int> gquiz;
	gquiz.push_back(10);
	gquiz.push_front(20);
	gquiz.push_back(30);
	gquiz.push_front(15);
	cout << "The deque gquiz is : ";
	TraverseDq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.max_size() : " << gquiz.max_size();

	cout << "\ngquiz.at(2) : " << gquiz.at(2);
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop_front() : ";
	gquiz.pop_front();
	TraverseDq(gquiz);

	cout << "\ngquiz.pop_back() : ";
	gquiz.pop_back();
	TraverseDq(gquiz);

	return 0;

}