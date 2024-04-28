#include <iostream>
#include <vector>
#include <algorithm> // For std::find

int main()
{
    std::vector<int> myVector = {10, 20, 30, 40, 50};
    int elementToRemove = 20;

    // Find the element
    auto it = std::find(myVector.begin(), myVector.end(), elementToRemove);

    // Check if the element was found before trying to erase
    if (it != myVector.end())
    {
        myVector.erase(it);
    }

    // Printing the vector after removing the element
    for (int elem : myVector)
    {
        std::cout << elem << " ";
    }

    return 0;
}
