#include <iostream>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int value) : key(key), val(value), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    int cap;
    unordered_map<int, Node *> cache; // {key -> node}
    Node *left;                       // LRU
    Node *right;                      // MRU

    // remove node from list
    void remove(Node *node)
    {
        Node *prev_node = node->prev;
        Node *next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    // insert node at right
    void insert(Node *node)
    {
        Node *prev_node = right->prev;
        Node *next_node = right;

        prev_node->next = node;
        next_node->prev = node;

        node->next = next_node;
        node->prev = prev_node;
    }

public:
    LRUCache(int capacity) : cap(capacity)
    {
        left = new Node(0, 0);  // LRU sentinel
        right = new Node(0, 0); // MRU sentinel

        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (cache.count(key))
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            remove(cache[key]);

            // Free allocated memory for the removed node
            delete cache[key];
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if (cache.size() > cap)
        {
            // remove from list & delete LRU from map
            Node *LRU = left->next;
            remove(LRU);
            cache.erase(LRU->key);

            // Free allocated memory for the removed node
            delete LRU;
        }
    }
};

int main()
{
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2);
    cout << lRUCache->get(1) << endl; // returns 1
    lRUCache->put(3, 3);              // evicts key 2
    cout << lRUCache->get(2) << endl; // returns -1 (not found)
    lRUCache->put(4, 4);              // evicts key 1
    cout << lRUCache->get(1) << endl; // returns -1 (not found)
    cout << lRUCache->get(3) << endl; // returns 3
    cout << lRUCache->get(4) << endl; // returns 4

    delete lRUCache;
    return 0;
}