#include <vector>
#include <string>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> result;
    result.reserve(n); // Allocate memory to prevent reallocations
    std::map<int, std::string> fizzBuzzDict = {
        {3, "Fizz"},
        {5, "Buzz"}};

    for (int i = 1; i <= n; i++)
    {
        std::string entry;
        for (const auto &kvp : fizzBuzzDict)
        {
            if (i % kvp.first == 0)
            {
                entry += kvp.second;
            }
        }
        if (entry.empty())
        {
            entry = std::to_string(i);
        }
        result.push_back(entry);
    }
    return result;
}
