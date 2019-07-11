class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        data = '/';
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for (int i = 0; i < word.length(); ++i) {
            char &c = word[i];
            if (root->tries.find(c) == root->tries.end()) {
                root->tries[c] = new Trie();
            }
            root = root->tries[c];
        }
        root->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        for (int i = 0; i < word.length(); ++i) {
            char &c = word[i];
            if (root->tries.find(c) == root->tries.end()) {
                return false;
            }
            root = root->tries[c];
        }
        return root->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        for (int i = 0; i < prefix.length(); ++i) {
            char &c = prefix[i];
            if (root->tries.find(c) == root->tries.end()) {
                return false;
            }
            root = root->tries[c];
        }
        return true;
    }
    
private:
    bool isWord;
    char data;
    std::map<char, Trie*> tries;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */