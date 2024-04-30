#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MyHashSet
{
private:
    vector<bool> elements;

public:
    MyHashSet()
    {
        this->elements = vector<bool>(1000001, false);
    }

    void add(int key)
    {
        this->elements[key] = true;
    }

    void remove(int key)
    {
        this->elements[key] = false;
    }

    bool contains(int key)
    {
        return this->elements[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]
int main()
{
    MyHashSet *myHashSet = new MyHashSet();
    myHashSet->add(1);
    myHashSet->add(2);
    cout << (myHashSet->contains(1) ? "true" : "false") << endl;
    cout << (myHashSet->contains(3) ? "true" : "false") << endl;
    myHashSet->add(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;
    myHashSet->remove(2);
    cout << (myHashSet->contains(2) ? "true" : "false") << endl;
    return 0;
}