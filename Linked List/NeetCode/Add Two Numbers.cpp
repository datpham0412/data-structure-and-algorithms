#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;
        int carry = 0;
        while (list1 != nullptr || list2 != nullptr || carry != 0)
        {
            int val1 = list1 != nullptr ? list1->val : 0;
            int val2 = list2 != nullptr ? list2->val : 0;

            // new digit
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            current->next = new ListNode(sum);

            current = current->next;
            if (list1 != nullptr)
                list1 = list1->next;
            if (list2 != nullptr)
                list2 = list2->next;
        }
        return dummy->next;
    }
};

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
    ListNode *list1 = nullptr;
    list1 = new ListNode(9);
    list1->next = new ListNode(9);

    ListNode *list2 = nullptr;
    list2 = new ListNode(8);
    list2->next = new ListNode(8);

    Solution *solution = new Solution();
    ListNode *listResult = solution->addTwoNumbers(list1, list2);
    cout << "The result is: ";
    printList(listResult);
    return 0;
}