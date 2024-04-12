#include <iostream>
#include <string>

int main()
{
    // Create a string and append numbers 1 to 10 separated by spaces
    std::string numbers;
    for (int i = 1; i <= 10; ++i)
    {
        numbers += std::to_string(i) + " ";
    }

    // Output the created string
    std::cout << "Generated numbers: " << numbers << std::endl;

    // Parse the string and sum the numbers
    int sum = 0;
    size_t pos = 0;
    while (pos < numbers.length())
    {
        size_t space = numbers.find(' ', pos);
        if (space == std::string::npos)
            break;
        sum += std::stoi(numbers.substr(pos, space - pos));
        pos = space + 1;
    }

    // Output the sum
    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}
