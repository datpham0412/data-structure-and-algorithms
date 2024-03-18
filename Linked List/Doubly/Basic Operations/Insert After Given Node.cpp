#include <iostream>

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode() : data(0), next(nullptr), prev(nullptr) {}
    ListNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};
// Time : O(1)
// Space: O(1)
void insertAfter(ListNode *prev_node, int new_data)
{
    ListNode *new_node = new ListNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node != nullptr)
    {
        new_node->next->prev = new_node;
    }
}

void push(ListNode **head_ref, int new_data)
{
    ListNode *new_node = new ListNode(new_data);
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if ((*head_ref) != nullptr)
    {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

ListNode *getLastNode(ListNode *head)
{
    ListNode *last = head;
    while (last != nullptr && last->next != nullptr)
    {
        last = last->next;
    }
    return last;
}
void printListForward(ListNode *head)
{
    ListNode *last;
    cout << "\nTraversal in forward direction: \nNULL -> ";
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
}
void printListBackward(ListNode *head)
{
    ListNode *last = getLastNode(head);
    cout << "-> NULL\nTraversal in backward direction: \nNULL -> ";
    while (last != nullptr)
    {
        cout << last->data << " -> ";
        last = last->prev;
    }
    cout << "-> NULL";
}

int main()
{
    ListNode *head = nullptr;
    ListNode *node1 = new ListNode(100);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    insertAfter(head->next, 100);
    printListForward(head);
    printListBackward(head);

    return 0;
}
