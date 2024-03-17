#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node () : data(0), next(nullptr) {}
    Node (int data) : data(data), next(nullptr){}
    Node (int data, Node* next) : data(data), next(next){}
    
};

class Solution {
public:
    Node* reverseList(Node* head) {
        Node* current = head;
        Node* prev_node = nullptr;
        while (current != nullptr){
            Node* temp = current -> next;
            current -> next = prev_node;
            prev_node = current;
            current = temp;
        }
        return prev_node;
    }
};

void printList(Node* head){
    while (head != nullptr){
        std::cout << head -> data << " -> ";
        head = head -> next;
    }
}

int main(){
    Node* head = nullptr;
    head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = new Node(5);

    std::cout << "Original List: ";
    printList(head);

    
    

    Solution* solution = new Solution();
    Node* reversedHead = solution->reverseList(head);

    
    std:: cout << "Reversed List: "; 
    printList(reversedHead);

    while (reversedHead != nullptr){
        Node* temp = reversedHead;
        reversedHead = reversedHead -> next;
        delete temp;
    }

    delete solution;
}