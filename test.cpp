#include <iostream>

// Define a node in the linked list
struct Node {
    int data; // Data carried by the node
    Node* next; // Pointer to the next node in the list
    
    // Constructor initializes the node with data and sets next to nullptr
    Node(int data) : data(data), next(nullptr) {}
};

// Function to search for an element in the linked list
bool search(Node* head, int key) {
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
        if (search(head, key)) {
            std::cout << key << " found in the linked list." << std::endl;
        } else {
            std::cout << key << " not found in the linked list." << std::endl;
        }
    }

    // Clean up memory: delete all nodes to prevent memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
