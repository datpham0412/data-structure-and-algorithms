#include <iostream>
#include <sstream>

int main()
{
    // Create an ostringstream and append numbers 1 to 10 separated by spaces
    std::ostringstream oss;
    for (int i = 1; i <= 10; ++i)
    {
        oss << i << " ";
    }

    // Convert the ostringstream content to a string
    std::string numbers = oss.str();

    // Output the created string
    std::cout << "Generated numbers: " << numbers << std::endl;

    // Use an istringstream to parse the string and sum the numbers
    std::istringstream iss(numbers);
    int sum = 0, value;
    while (iss >> value)
    {
        sum += value;
    }

    // Output the sum
    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}
