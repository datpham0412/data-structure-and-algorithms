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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        // Find the middle of the list
        ListNode *prev_node = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            prev_node = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev_node->next = nullptr;
        ListNode *list1 = head;
        ListNode *list2 = reverseList(slow);
        mergeList(list1, list2);
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev_node = nullptr;
        while (current != nullptr)
        {
            ListNode *temp = current->next;
            current->next = prev_node;
            prev_node = current;
            current = temp;
        }
        return prev_node;
    }
    void mergeList(ListNode *list1, ListNode *list2)
    {
        while (list1 != nullptr)
        {
            ListNode *p1 = list1->next;
            ListNode *p2 = list2->next;

            list1->next = list2;
            if (p1 == nullptr)
            {
                break;
            }
            list2->next = p1;
            list1 = p1;
            list2 = p2;
        }
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " -> ";
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

    cout << "The original list is: ";
    printList(node1);
    cout << endl;

    Solution *solution = new Solution();
    solution->reorderList(node1);
    cout << "The list after reordered is: ";
    printList(node1);
    cout << endl;
    return 0;
}