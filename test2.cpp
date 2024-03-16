#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data){
		this -> data = data;
		this -> next = nullptr;
	}
	~Node(){
		Node* current = this;
		while (current != nullptr){
			Node* temp = current;
			current = current -> next;
			delete temp;
		}
	}
};

bool searchElement(Node *head, int key){
	Node *current = head;
	while (current != nullptr){
		if(current -> data = key){
			return true;
		}
		current = current -> next;
	}
	return false;
}

void printList(Node *head){
	while(head != nullptr){
		cout << head -> data << "-> ";
		head = head -> next;
	}
}

int main(){
	Node *head = nullptr;
	head = new Node(1);
	head -> next = new Node(2);
	head -> next -> next = new Node (3);
	head -> next -> next -> next = new Node (4);

	printList(head);
	int keys[] = {3,6};
	for (int key : keys){
		if(searchElement(head, key)){
			cout << endl << key << " found in Linked List"; 
		}
		else{
			cout << key << " not found in Linked List" << endl;
		}
	}
	return 0;
}

