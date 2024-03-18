#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int data) : data(data), next(nullptr) {}
    ListNode(int data, ListNode *next) : data(data), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthNodeFromEndOfTheList(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy;
        ListNode *fast = head;

        while (n > 0 && fast != nullptr)
        {
            fast = fast->next;
            n--;
        }

        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
}

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    cout << "Original List is: ";
    printList(node1);
    cout << endl;

    Solution *solution = new Solution();
    ListNode *result = solution->removeNthNodeFromEndOfTheList(node1, 2);
    cout << "List after remove is: ";
    printList(result);
    cout << endl;

    return 0;
}