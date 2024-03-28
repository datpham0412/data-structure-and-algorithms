#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
        {
            return NULL;
        }

        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }

        return lists.front();
    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy;
        ListNode *current = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
};

// Helper function to create a linked list from a vector of values
ListNode *createList(const vector<int> &values)
{
    ListNode dummy;
    ListNode *current = &dummy;
    for (int val : values)
    {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    vector<ListNode *> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})};

    Solution solution;
    ListNode *result = solution.mergeKLists(lists);

    cout << "Merged list: ";
    printList(result);

    return 0;
}
