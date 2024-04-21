class TrieNode{
    public:
    TrieNode* children[26];
    bool isWord;
    TrieNode (){
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        isWord = false;
    }
};
class WordDictionary {
    private:
    TrieNode* root;
    bool searchInWord(string &word, int i, TrieNode* node){
        if (node == nullptr){
            return false;
        }
        if (i == word.size()){
            return node -> isWord;
        }
        if (word[i] != '.'){
            return searchInWord(word, i + 1, node -> children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++){
            if(searchInWord(word, i + 1, node -> children[j])){
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        int current = 0;
        for (int i = 0; i < word.size(); i++){
            current = word[i] - 'a';
            while (node -> children[current] == nullptr){
                node -> children[current] = new TrieNode();
            }
            node = node -> children[current];
        }
        node -> isWord = true;
    }
    
    bool search(string word) {
        return searchInWord(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */