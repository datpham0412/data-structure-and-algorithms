#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode *next) : val(value), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev_node = dummy;
        ListNode *current = dummy->next;
        ListNode *temp = nullptr;
        int count = k;
        while (current != nullptr)
        {
            if (count > 1)
            {
                temp = prev_node->next;
                prev_node->next = current->next;
                current->next = current->next->next;
                prev_node->next->next = temp;
                count--;
            }
            else
            {
                prev_node = current;
                current = current->next;
                count = k;
                ListNode *end = current;
                for (int i = 0; i < k; i++)
                {
                    if (end == nullptr)
                    {
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        return dummy->next;
    }
};

void printLinkedList(const ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " -> ";
        node = node->next;
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

    cout << "Original List: ";
    printLinkedList(node1);
    cout << endl;

    int k = 2;
    Solution *solution = new Solution();
    ListNode *reverse_node1 = solution->reverseKGroup(node1, k);
    cout << "Reversed List: ";
    printLinkedList(reverse_node1);
    cout << endl;
    delete solution;
    return 0;
}