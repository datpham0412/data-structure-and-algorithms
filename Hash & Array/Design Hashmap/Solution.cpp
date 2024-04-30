#include <iostream>

class MyHashMap
{
private:
    int data[1000001];

public:
    MyHashMap()
    {
        std::fill(data, data + 1000001, -1); // Initialize all values to -1
    }

    void put(int key, int value)
    {
        data[key] = value; // Store the value at the index corresponding to the key
    }

    int get(int key)
    {
        return data[key]; // Return the value at the index corresponding to the key
    }

    void remove(int key)
    {
        data[key] = -1; // Reset the value at the index corresponding to the key to -1
    }
};

int main()
{
    MyHashMap myHashMap;

    // Demonstrate adding elements
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);

    // Retrieve elements
    std::cout << "The value for key 1 is: " << myHashMap.get(1) << std::endl; // Outputs 1
    std::cout << "The value for key 3 is: " << myHashMap.get(3) << std::endl; // Outputs -1 (not found)

    // Update an existing value
    myHashMap.put(2, 3);
    std::cout << "The updated value for key 2 is: " << myHashMap.get(2) << std::endl; // Outputs 3

    // Remove a key
    myHashMap.remove(2);
    std::cout << "The value for key 2 after removal is: " << myHashMap.get(2) << std::endl; // Outputs -1 (removed)

    return 0;
}
