#include <iostream>

using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int data) : data(data), next(nullptr){}
    ListNode(int data, ListNode* next) : data(data), next(next) {}
};

class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;

        while (n > 0 && fast != nullptr){
            fast = fast -> next;
            n --;
        }
        while (fast != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return dummy -> next;
    }
};

void printList(ListNode* head){
    while (head != nullptr){
        cout << head -> data << " -> ";
        head = head -> next;
    }
}

int main() {
    ListNode* head = nullptr;
    head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);

    cout << "Original List: ";
    printList(head);
    cout << endl;

    Solution* solution = new Solution();
    solution ->removeNthFromEnd(head, 2);
    cout << "New List: ";
    printList(head);
    cout << endl;

    return 0;



}
