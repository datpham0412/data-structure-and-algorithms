#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> charMap;   // Maps character in pattern to indices
        unordered_map<string, int> wordMap; // Maps word in s to indices
        int i = 0;
        int n = pattern.size(); // Size of pattern
        string word;            // Variable to store each word from s as it's processed
        istringstream iss(s);   // Used to stream over words in s
        while (iss >> word)
        {
            // Read next word from s into word
            if (i == n)
            {
                // If there are more words in s than character in patter -> return false
                return false;
            }
            char ch = pattern[i]; // Represent for each character in pattern
            // This condition is for checking inconsistency;
            // if current pattern or word has seen before, they must have the same index
            if (charMap[ch] != wordMap[word])
            {
                return false;
            }
            charMap[ch] = wordMap[word] = i + 1;
            i++;
        }
        // After looping through words, check if we've exhausted the pattern completely
        // i should exactly match the length of the pattern.
        return i == n;
    }
};

int main()
{
    Solution solution;
    string pattern = "abba";
    string s = "dog cat cat dog";
    bool result = solution.wordPattern(pattern, s);
    cout << (result ? "true" : "false");
    return 0;
}