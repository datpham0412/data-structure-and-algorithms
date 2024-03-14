#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node () : data(data), next(nullptr) {}
    Node (int data) : data(data), next(nullptr){}
    Node (int data, Node* next) : data(data), next(next){}
    ~Node (){
        Node* current = this;
        while (current != nullptr){
            Node* temp = current;
            current = current -> next;
            delete temp;
        }
    }
};

class Solution{
public:
    Node* mergeTwoSortedList(Node* list1, Node* list2){
        Node* dummy = new Node();
        Node* current = dummy;
        while (list1 != nullptr && list2 != nullptr){
            if (list1 -> data <= list2 -> data){
                current -> next = list1;
                list1 = list1 -> next;
            }else{
                current -> next = list2;
                list2 = list2 -> next;
            }
            current = current -> next;
        }
        if (list1 == nullptr){
            current -> next = list2;
        }else{
            current -> next = list1;
        }
        return dummy -> next;

    }

};

void printList(Node* head){
    while (head != nullptr){
        std::cout << head -> data << " -> ";
        head = head -> next;
    }
}


int main(){
    Node* head1 = new Node(1);
    head1 -> next = new Node(3);
    head1 -> next -> next = new Node(5);

    Node* head2 = new Node(2);
    head2 -> next = new Node(4);
    head2 -> next -> next = new Node(6);

    Node *head3 = nullptr;

    Solution* solution = new Solution();
    Node* result = solution -> mergeTwoSortedList(head1, head2);
    printList(result);

    delete solution;
    
    return 0;
}