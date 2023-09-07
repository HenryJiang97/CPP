struct Trie {
    // Definition of TrieNode
    struct TrieNode {
        vector<TrieNode*> children;
        bool ifEnd;
        TrieNode() {
            children = vector<TrieNode*>(26);
            ifEnd = 0;
        }
    };

    //////////////////////////////////////////////////////////
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a string
    void insert(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->ifEnd = 1;
    }
    
    // Search for a string
    bool search(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)    return 0;
            p = p->children[c - 'a'];
        }
        return p->ifEnd;
    }
};