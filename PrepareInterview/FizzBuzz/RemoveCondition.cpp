std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> result;
    result.reserve(n); // Reserve space for n elements to avoid reallocation
    for (int i = 1; i <= n; i++)
    {
        std::string entry;
        if (i % 3 == 0)
        {
            entry += "Fizz";
        }
        if (i % 5 == 0)
        {
            entry += "Buzz";
        }
        if (entry.empty())
        {
            entry = std::to_string(i);
        }
        result.push_back(entry);
    }
    return result;
}
