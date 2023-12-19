class TrieNode {
public:
    static const int ALPHABET_SIZE = 26;
    TrieNode* children[ALPHABET_SIZE] = { nullptr };
    bool isEndOfWord;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
        memset(root->children, 0, sizeof(root->children));
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode(); // create a new node
            node = node->children[index]; // move to the next node
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return (node != nullptr && node->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return (node != nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */