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

void insertBefore(ListNode **head_ref, ListNode *next_node, int new_data)
{
    if (next_node == nullptr)
    {
        cout << "The given node can not be null";
        return;
    }
    ListNode *new_node = new ListNode(new_data);
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;

    if (new_node->prev != nullptr)
    {
        new_node->prev->next = new_node;
    }
    else
    {
        (*head_ref) = new_node; // if the node is at the beginning of the
    }
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
    cout << "NULL";
}
void printListBackward(ListNode *head)
{
    ListNode *last = getLastNode(head);
    cout << "\nTraversal in backward direction: \nNULL -> ";
    while (last != nullptr)
    {
        cout << last->data << " -> ";
        last = last->prev;
    }
    cout << " NULL";
}

int main()
{
    ListNode *head = nullptr;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    insertBefore(&head, head, 100);
    printListForward(head);
    printListBackward(head);

    return 0;
}