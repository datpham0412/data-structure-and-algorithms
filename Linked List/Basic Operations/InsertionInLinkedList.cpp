#include <iostream>

// Define a node in the linked list
struct Node {
    int data; // Data carried by the node
    Node* next; // Pointer to the next node in the list
    // Default constructor
    Node() : data(data), next(nullptr){} // Initializes data to 0 and next to nullptr
    Node (){
        this -> data = data;
        this -> next = nullptr;
    }
    // Constructor initializes the node with data and sets next to nullptr
    Node(int data) : data(data), next(nullptr) {}
    // Node (int data){
    //     this->data = data;
    //     this->next = nullptr;
    // }
};

// Function to add a node to the end of the list
void append(Node** head_ref, int new_data) {
    // Allocate new node with given data
    Node* new_node = new Node();
    new_node ->data = new_data;

    // If the list is empty, new node becomes the head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Otherwise, find the last node
    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Insert the new node at the end of the list
    last->next = new_node;
}

// Function to insert a new node at the beginning of the list
void push(Node** head_ref, int new_data) {
    //1.  Allocate the new node and set its data
    Node* new_node = new Node();
    // 2. Put in the data
    new_node -> data = new_data;

    // 3. Make next of the new node as head
    new_node->next = *head_ref;

    // 4. Move the head to point to the new node
    *head_ref = new_node;
}

// Function to insert a new node after the given prev_node
void insertAfter(Node* prev_node, int new_data) {
    // 1. Check if the given prev_node is NULL
    if (prev_node == nullptr) {
        std::cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. Allocate new node
    Node* new_node = new Node(new_data);

    // 3. Put in the data
    new_node->data = new_data;

    // 4. Make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // 5. Move the next of prev_node as new_node
    prev_node->next = new_node;
}

// Function to print the linked list
void printList(Node* node) {
    // Iterate over the list and print each node's data
    while (node != nullptr) {
        std::cout << node->data << " -> ";
        node = node->next;
    }
}

// Main program to demonstrate the linked list operations
int main() {
    Node* head = nullptr; // Start with the empty list

    // Append some nodes to the list
    append(&head, 6); // Append 6. List become 6 -> nullptr
    append(&head, 7); // Append 7. List become 6->7-> nullptr
    append(&head, 1); // Append 1. List become 6->7->1-> nullptr
    push(&head, 100); // List becomes 100->6->7->1->nullptr
    // Insert 50 after the first node (which currently has the value 100)
    insertAfter(head, 50); // List becomes 100->50->6->7->1->nullptr
    
    // Insert at third node:
    // Navigate to the third node
    Node* thirdNode = head;
    for (int i = 0; i < 2 && thirdNode != nullptr; ++i) { // Loop 2 times to reach the third node
        thirdNode = thirdNode->next;
    }

    // Check if the third node exists and then insert after it
    if (thirdNode != nullptr) {
        insertAfter(thirdNode, 12); // Inserts 12 after the third node
    }

    // Print the created linked list
    std::cout << "HEAD ->  ";
    printList(head); // Output will be 100 50 6 7 1
    std::cout << " NULL";

    // Clean up memory: delete all nodes to prevent memory leaks
    while (head != nullptr) {
        Node* temp = head; // Temporary pointer to the current node
        head = head->next; // Move head to the next node
        delete temp; // Delete the current node
    }

    return 0;
}
