#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagram_map;

    for (const std::string& word : strs) {
        std::string sorted_word = word;
        std::sort(sorted_word.begin(), sorted_word.end());
        
        anagram_map[sorted_word].push_back(word);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& pair : anagram_map) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    std::vector<std::string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = groupAnagrams(strs1);

    for (const auto& group : result) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
