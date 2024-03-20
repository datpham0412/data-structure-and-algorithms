#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> nodes;
        Node *current = head;
        while (current != nullptr)
        {
            nodes[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        while (current != nullptr)
        {
            nodes[current]->next = nodes[current->next];
            nodes[current]->random = nodes[current->random];
            current = current->next;
        }

        return nodes[head];
    }
};

Node *createList(const vector<vector<int>> &values)
{
    vector<Node *> nodes(values.size(), nullptr);

    // First pass to create all nodes
    for (int i = 0; i < values.size(); i++)
    {
        nodes[i] = new Node(values[i][0]);
    }

    // Second pass to assign next and random pointers
    for (int i = 0; i < values.size(); i++)
    {
        if (i < values.size() - 1)
        {
            nodes[i]->next = nodes[i + 1];
        }
        int randomIndex = values[i][1];
        nodes[i]->random = (randomIndex != -1) ? nodes[randomIndex] : NULL;
    }

    return nodes.front(); // return the head of the list
}

// Corrected Utility function to print the list
void printList(Node *head)
{
    Node *current = head;
    unordered_map<Node *, int> nodeToIndex;
    int index = 0;
    // Create a mapping from node to index
    while (current != nullptr)
    {
        nodeToIndex[current] = index++;
        current = current->next;
    }

    // Reset current to head for printing
    current = head;
    while (current != nullptr)
    {
        cout << "[" << current->val << ",";
        if (current->random == nullptr)
        {
            cout << "null";
        }
        else
        {
            // Print the index of the node that random points to
            cout << nodeToIndex[current->random];
        }
        cout << "], ";
        current = current->next;
    }
    cout << endl;
}
int main()
{
    // The input
    vector<vector<int>> input = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};

    // Create the linked list
    Node *list = createList(input);

    // Print the original list
    cout << "Original list:" << endl;
    printList(list);

    // Use the Solution class to copy the list
    Solution solution;
    Node *copiedList = solution.copyRandomList(list);

    // Print the copied list
    cout << "Copied list:" << endl;
    printList(copiedList);

    // Cleanup memory
    Node *current = copiedList;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
