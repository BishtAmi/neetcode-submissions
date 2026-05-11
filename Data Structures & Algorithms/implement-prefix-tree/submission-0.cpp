class PrefixTree {
   public:
    class Trie {
       public:
        bool isEnd;
        Trie* child[26];
    };
    PrefixTree() {}

    Trie* getNode() {
        Trie* temp = new Trie();
        for (int i = 0; i < 26; i++) {
            temp->child[i] = NULL;
        }
        temp->isEnd = false;
        return temp;
    }
    Trie *root = getNode();
    void insert(string word) {
        Trie* temp = root;
        for (auto ch : word) {
            if (temp->child[ch - 'a'] == NULL) {
                temp->child[ch - 'a'] = getNode();
            }
            temp = temp->child[ch - 'a'];
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        Trie* temp = root;
        for (auto ch : word) {
            if (temp->child[ch - 'a'] == NULL) {
                return false;
            }
            temp = temp->child[ch - 'a'];
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* temp = root;
        for (auto ch : prefix) {
            if (temp->child[ch - 'a'] == NULL) {
                return false;
            }
            temp = temp->child[ch - 'a'];
        }
        return true;
    }
};
