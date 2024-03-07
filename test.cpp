// Time complexity: O(n)
// Space complexity: O(1)


#include <iostream>

// Define a node in the linked list
class ListNode {
public:
    int value; // Data carried by the node
    ListNode* next; // Pointer to the next node in the list
    
    // Constructor initializes the node with data and sets next to nullptr
    // ListNode(int value) : value(value), next(nullptr) {}
    ListNode (int value){
        this-> value = value;
        this -> next = nullptr;
    }

    // Destructor to free memory for the linked list
    ~ListNode() {
        // Traverse the list and delete each node
        ListNode* current = this;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Function to search for an element in the linked list
bool search(ListNode* head, int key) {
  	if (head == nullptr){
		return false;
	}    
	if (head -> value == key){
		return true;
	}
	return search(head->next, key);
}

// Function to print the linked list
void printList(ListNode* head) {
    // Iterate over the list and print each node's data
    while (head != nullptr) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

// Main program to demonstrate searching in the linked list
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

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
    // ListNode* current = head;
    // while (current != nullptr) {
    //     ListNode* temp = current;
    //     current = current->next;
    //     delete temp;

    // No need to explicitly delete the linked list here
    // The destructor of the head node will take care of deallocating memory for the entire list

    return 0;
}
