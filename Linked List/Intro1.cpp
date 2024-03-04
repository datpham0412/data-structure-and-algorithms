# include <iostream> 

// Define a node in the linked list
struct Node {
    int data; // Data carried by the node
    Node *next; // Pointer to the next node in the list

    // Constructor initializes the node with data and sets next to nullptr
    Node(int data): data(data), next(nullptr) {}
};

// Function to add a node to the end of the list
void append(Node** head_ref, int new_data){
    // Allocate new node with given data
    Node* new_node = new Node(new_data);

    // If the list is empty, new node becomes the head
    if(*head_ref == nullptr){
        *head_ref = new_node;
        return;
    }

    // Otherwise, find the last node
    Node* last = *head_ref;
    while(last->next != nullptr){
        last = last->next;
    }
    // Insert the new node at the end of the list
    last->next = new_node;
}

// Function to print the linked list
void printList(Node* node){
    // Iterate over the list and print each node's data
    while (node != nullptr){
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main program to demonstrate the linked list operations
int main(){
    Node* head = nullptr; // Start with the empty list
    // Append some nodes to the list
    append(&head, 6); // Append 6. List become 6 -> nullptr
    append(&head, 7); // Append 7. List become 6->7-> nullptr
    append(&head, 1); // Append 1. List become 6->7->1-> nullptr

    // Print the created linked list
    std::cout << "Created Linked list is: ";
    printList(head); //Output will be 6 7 1

    //Clean up memory: delete all nodes to prevent memory leaks
    while(head != nullptr){
        Node *temp = head; // Temporary pointer to the current node
        head = head -> next; // Move head to the next node
        delete temp; // Delete the current node
    }
    return 0;
}