/*
In some ways we can crete the specific function and crete are own compare function and many more things

*/
#include<iostream>
#include<queue>
using namespace std;
class Person{
public:
    int age;
    float height;
    Person(int a,float h){
        age=a;
        height=h;
    }
};
class Mycmp{
    public:
   bool operation(Person const& a,Person const& b){
    a.height<b.height;
   }
};
int main(){
    priority_queue<Person,vector<Person>,Mycmp> pq;
}