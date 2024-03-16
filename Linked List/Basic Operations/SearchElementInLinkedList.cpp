// Time complexity: O(n)
// Space complexity: O(1)


#include <iostream>

// Define a node in the linked list
class Node {
public:
    int data; // Data carried by the node
    Node* next; // Pointer to the next node in the list
    
    // Constructor initializes the node with data and sets next to nullptr
    // Node(int data) : data(data), next(nullptr) {}
    Node (int data){
        this-> data = data;
        this -> next = nullptr;
    }

    // Destructor to free memory for the linked list
    ~Node() {
        // Traverse the list and delete each node
        Node* current = this;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Function to search for an element in the linked list
bool searchIterative(Node* head, int key) {
    Node* current = head; // Start from the head of the list

    // Iterate over the list
    while (current != nullptr) {
        // If the current node contains the key, return true
        if (current->data == key) {
            return true;
        }
        // Move to the next node
        current = current->next;
    }

    // If key is not found, return false
    return false;
}
bool searchRecursive(Node* head, int key) {
    if (head == nullptr){
        return false;
    }
    if (head -> data == key){
        return true;
    }
    return searchRecursive(head->next, key);
}

// Function to print the linked list
void printList(Node* head) {
    // Iterate over the list and print each node's data
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Main program to demonstrate searching in the linked list
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the linked list
    std::cout << "Linked list: ";
    printList(head);

    // Search for elements in the linked list
    int keys[] = {3, 6};
    for (int key : keys) {
        if (searchRecursive(head, key)) {
            std::cout << key << " found in the linked list." << std::endl;
        } else {
            std::cout << key << " not found in the linked list." << std::endl;
        }
    }
    // Node* current = head;
    // while (current != nullptr) {
    //     Node* temp = current;
    //     current = current->next;
    //     delete temp;

    // No need to explicitly delete the linked list here
    // The destructor of the head node will take care of deallocating memory for the entire list

    return 0;
}
