#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string str)
{
    unordered_map<char, int> charMap;   // Maps characters in pattern to indices
    unordered_map<string, int> wordMap; // Maps words in str to indices
    istringstream in(str);              // Used to stream over the words in str
    int i = 0;                          // Index to iterate over the pattern
    string word;                        // Variable to store each word from str as it's processed

    while (in >> word)
    { // Read next word from str into word
        if (i == pattern.size())
        {
            // If there are more words than characters in the pattern, return false
            return false;
        }

        char ch = pattern[i]; // Get the current character from the pattern

        // Check for inconsistency: if current pattern character or word has been seen before,
        // they must map to the same index
        if (charMap[ch] != wordMap[word])
        {
            return false;
        }

        // Update the maps with the current index (i+1) to differentiate from default value of 0
        charMap[ch] = wordMap[word] = i + 1;

        i++; // Move to the next character in the pattern
    }

    // After looping through words, check if we've exhausted the pattern completely
    // i should exactly match the length of the pattern
    return i == pattern.size();
}

int main()
{
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << boolalpha << wordPattern(pattern, str) << endl; // Output: true

    pattern = "abba";
    str = "dog cat cat fish";
    cout << boolalpha << wordPattern(pattern, str) << endl; // Output: false

    pattern = "aaaa";
    str = "dog cat cat dog";
    cout << boolalpha << wordPattern(pattern, str) << endl; // Output: false

    return 0;
}
