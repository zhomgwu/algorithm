
/*
思路：使用Trie的方式解答，则需要创建一棵Trie树，先将所有的节点插入到树中，以输入数组的特点，答案的每一个小部分应该都为word。
遍历每一个word，依次判断该word的每一个小部分是否在树中能找到，找到则为符合，并取长度最长的word。如果有长度相同的，以字典序比较。
*/

struct TrieNode {
    TrieNode(char c) {
        data = c;
        isWord = false;
    }
    char data;
    bool isWord;
    std::map<char, TrieNode*> next;
    
    void insert(string word) {
        TrieNode *cur = this;
        for (auto c : word) {
            if (cur->next.find(c) == cur->next.end()) {
                cur->next[c] = new TrieNode(c);
            }
            cur = cur->next[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode * t = this;
        for (int i = 0; i < word.length(); ++i) {
            char &c = word[i];
            if (t->next.find(c) == t->next.end() ||
               !t->next[c]->isWord) {
                return false;
            }
            t = t->next[c];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        TrieNode *root = new TrieNode('/');
        for (auto word : words) {
            root->insert(word);
        }
        
        for (auto word : words) {
            if (!root->search(word)) {
                continue;
            } 
            if (word.length() > ans.length()) {
                ans = word;   
            } else if (word.length() == ans.length()) {
                for (int i = 0; i < word.length(); ++i) {
                    if (word[i] == ans[i]) {
                        continue;
                    }
                    if (word[i] < ans[i]) 
                        ans = word;
                    break;
                }
            }
        }
        return ans;
    }
};