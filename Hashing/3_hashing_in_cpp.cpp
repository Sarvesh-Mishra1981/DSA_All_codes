/*
set<int> s;
just similar to the unordered_set here the elements that sre stored is not repeated but in the set the elemnts are stored in the 
sorted order and hence it takes O(logn) time to srerach insert and delete it but in the unordered_set the order is not fixed
hence it take sthe 0(1) time


just similar in the map and the unordered_map here the insertio style is differenty rest the function are the same but in the umap the order 
is not fixed but in the map the order is fixed that it id in the sorted oder

*/

// C++ program to illustrate Map container

#include <iostream> 
#include <iterator> 
#include <map> 

using namespace std; 

int main() 
{ 
    // empty map container 
    map<int, int> mp; 

    // Insert elements in random order 
    // First element of the pair is the key
    // second element of the pair is the value
    mp.insert(pair<int, int>(1, 40)); 
    mp.insert(pair<int, int>(2, 30)); 
    mp.insert(pair<int, int>(3, 60)); 
    mp.insert(pair<int, int>(4, 20)); 
    mp.insert(pair<int, int>(5, 50)); 
    mp.insert(pair<int, int>(6, 50)); 
    mp.insert(pair<int, int>(7, 10)); 

    // printing map mp 
    map<int, int>::iterator itr; 
    cout << "The map mp is : \n"; 
    cout << "KEY\tELEMENT\n"; 
    for (itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << itr->first 
            << '\t' << itr->second << '\n'; 
    } 


    unordered_map<string, int> umap; 

    // inserting values 
    umap.insert({"GeeksforGeeks", 10}); 
    umap.insert({"Practice", 20}); 
    umap.insert({"Contribute", 30}); 

    // Traversing an unordered map 
      cout << "The map umap is : \n"; 
    cout << "KEY\t\tELEMENT\n"; 
    for (auto itr = umap.begin(); itr!= umap.end(); itr++) 
      cout << itr->first 
            << '\t' << itr->second << '\n';

    return 0; 
}