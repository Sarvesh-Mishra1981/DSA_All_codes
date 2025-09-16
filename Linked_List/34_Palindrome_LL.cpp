#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* MiddleofLL(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Reverse linked list recursively
Node* ReverseIt(Node* prev, Node* curr) {
    if (curr == NULL) return prev;
    Node* after = curr->next;
    curr->next = prev;
    return ReverseIt(curr, after);
}

// Check if linked list is palindrome
bool Ispalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find middle
    Node* middle = MiddleofLL(head);

    // Step 2: Reverse second half
    Node* secondHalf = ReverseIt(NULL, middle->next);

    // Step 3: Compare first half and reversed second half
    Node* firstHalf = head;
    Node* tempSecond = secondHalf;
    bool isPal = true;
    while (tempSecond != NULL) {
        if (firstHalf->val != tempSecond->val) {
            isPal = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }
    return isPal;
}

int main() {
    Node* head = new Node(10);
    Node* temp = new Node(20);
    Node* temp2 = new Node(30);
    Node* temp3 = new Node(20);
    Node* temp4 = new Node(10);

    head->next = temp;
    head->next->next = temp2;
    head->next->next->next = temp3;
    head->next->next->next->next = temp4;

    cout << (Ispalindrome(head) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
