#include <iostream>
#include <string>
using namespace std;
class TrieNode {
    public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i ++){
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Trie {
    private:
        TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int current = 0;
        for (int i = 0; i < word.size(); i++){
            current = word[i] - 'a';
            if(node -> children[current] == nullptr){
                node -> children[current] = new TrieNode;
            }
            node = node -> children[current];
        }
        node -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int current = 0;
        for(int i = 0; i < word.size(); i++){
            current = word[i] - 'a';
            if(node -> children[current] == nullptr){
                return false;
            }
            node = node -> children[current];
        }
        return node -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int current = 0;
        for (int i = 0; i < prefix.size(); i++){
            current = prefix[i] - 'a';
            if(node -> children[current] == nullptr){
                return false;
            }
            node = node -> children[current];
        }
        return true;
    }
};
int main() {
    // Create a new Trie object.
    Trie* obj = new Trie();
    
    // Test case 1: Insert the word "apple".
    obj->insert("apple");
    std::cout << "Inserted 'apple'" << std::endl;
    
    // Test case 2: Search for the word "apple".
    bool search1 = obj->search("apple");
    std::cout << "Search 'apple': " << (search1 ? "Found" : "Not Found") << std::endl;
    
    // Test case 3: Search for the word "app".
    bool search2 = obj->search("app");
    std::cout << "Search 'app': " << (search2 ? "Found" : "Not Found") << std::endl;
    
    // Test case 4: Check if prefix "app" exists.
    bool startsWith1 = obj->startsWith("app");
    std::cout << "StartsWith 'app': " << (startsWith1 ? "Exists" : "Does Not Exist") << std::endl;
    
    // Test case 5: Insert the word "app".
    obj->insert("app");
    std::cout << "Inserted 'app'" << std::endl;
    
    // Test case 6: Search for the word "app" again.
    bool search3 = obj->search("app");
    std::cout << "Search 'app' after inserting: " << (search3 ? "Found" : "Not Found") << std::endl;

    // Clean up the Trie to prevent memory leak.
    delete obj;

    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */