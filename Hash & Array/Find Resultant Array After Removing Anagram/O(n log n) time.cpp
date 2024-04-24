// Time: O(n log n)
// Space: O(n)

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
        string prev_word = "";
        vector<string> result;
        for (string &word : words)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            if (sorted_word != prev_word)
            {
                result.push_back(word);
                prev_word = sorted_word;
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