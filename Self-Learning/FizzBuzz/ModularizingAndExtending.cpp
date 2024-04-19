#include <vector>
#include <string>

std::string getFizzBuzzStatus(int i)
{
    std::string result;
    if (i % 3 == 0)
        result += "Fizz";
    if (i % 5 == 0)
        result += "Buzz";
    return result.empty() ? std::to_string(i) : result;
}

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> result;
    result.reserve(n);
    for (int i = 1; i <= n; i++)
    {
        result.push_back(getFizzBuzzStatus(i));
    }
    return result;
}
