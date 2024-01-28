#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

//strs: ["eat","tea","tan","ate","nat","bat"]
class Solution{
    public:
    std::vector<std::vector<std::string>> groupAnagrams (std::vector<std::string> &strs){
        // Create hashmap with key
        std::unordered_map<std::string, std::vector<std::string>> anagram_map;
        // sort word in strs (grouping together)
        for (std::string word : strs){
            std::string sorted_word = word;
            std::sort(sorted_word.begin(), sorted_word.end());
            // sorted_word: aet, aet, ant, aet, ant, abt
            //word: "eat","tea","tan","ate","nat","bat"
            anagram_map[sorted_word].push_back(word);
        }
        std ::vector<std::vector<std::string>>result;
        for (auto pair : anagram_map){
            result.push_back(pair.second);
        }
        return result;
    }
};

int main(){
    Solution solution;
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);
    for (auto group: result){
        for (std::string word : group){
            std::cout <<word<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;

}