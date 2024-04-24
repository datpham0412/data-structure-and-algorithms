// Time: O(n)
// Space :O(n)

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 2022.07.12

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> result;
        vector<int> prev_freq(26, 0);
        for (string &word : words)
        {
            vector<int> current_freq(26, 0);
            for (char &c : word)
            {
                current_freq[c - 'a']++;
            }
            if (result.empty() || current_freq != prev_freq)
            {
                result.push_back(word);
                prev_freq = current_freq;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result = solution.removeAnagrams(words);
    for (string word : result)
    {
        cout << word << " ";
    }
    return 0;
}