#include <vector>
#include <string>
#include <functional>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> result;
    result.reserve(n);

    auto fizz = [](int i)
    { return i % 3 == 0; };
    auto buzz = [](int i)
    { return i % 5 == 0; };

    for (int i = 1; i <= n; i++)
    {
        std::string entry;
        if (fizz(i))
            entry += "Fizz";
        if (buzz(i))
            entry += "Buzz";
        if (entry.empty())
            entry = std::to_string(i);

        result.push_back(entry);
    }
    return result;
}
