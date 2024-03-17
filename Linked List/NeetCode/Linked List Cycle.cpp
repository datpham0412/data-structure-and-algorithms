#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node () : data(0), next(nullptr){}
    Node (int data) : data(data), next(nullptr){}
    Node (int data, Node* next) : data(data), next(next){}

};

class Solution{
    public:
    bool linkedListCycle(Node* head){
        if(head == nullptr){return false;}
        Node* slow = head;
        Node* fast = head;

        while(fast -> next != nullptr && fast->next->next != nullptr){
            slow = slow -> next;
            fast = fast-> next -> next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }

};

void printList(Node* head){
    while(head != nullptr){
        cout << head -> data << " -> ";
        head = head -> next;
    }
}


int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node2;

    Solution* solution;
    cout << "Test Case 1: " << (solution -> linkedListCycle(node1) ? "true" : "false") << endl; 


    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node5 -> next = node6;
    node6 -> next = node7;
    node7 -> next = nullptr;

    cout << "Test Case 2: " << (solution -> linkedListCycle(node5) ? "true" : "false");
    return 0;
}