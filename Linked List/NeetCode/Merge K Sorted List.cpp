#include <iostream>
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
        {
            return nullptr;
        }
        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
            }
            n = (n + 1) / 2;
        }
        return lists.front();
    }

private:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = list1 != nullptr ? list1 : list2;
        return dummy->next;
    }
};

ListNode *createList(const vector<int> &values)
{
    ListNode dummy;
    ListNode *current = &dummy;

    for (int i = 0; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return dummy.next;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
}

int main()
{
    vector<ListNode *> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})};
    Solution *solution = new Solution();
    ListNode *result = solution->mergeKLists(lists);
    printList(result);
    return 0;
}