class Trie {
public:
    struct trieNode {
        bool endofword;
        trieNode* children[27];
    };

    trieNode* getNode() {
        trieNode* node = new trieNode();
        for (int i = 0; i < 27; i++) {
            node->children[i] = NULL;
        }
        node->endofword = false;
        return node;
    }

    trieNode* root;
    Trie() { root = getNode(); }

    void insert(string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = (word[i] == '/') ? 26 : word[i] - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endofword = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = (word[i] == '/') ? 26 : word[i] - 'a';
            if (crawler->children[idx] == NULL) {
                return false;
            }
            crawler = crawler->children[idx];
            if (crawler->endofword && i < word.length() - 1 && word[i + 1] == '/') {
                return false;  // Found a subfolder in the trie
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        Trie trie;
        for (string str : folder) {
            trie.insert(str);
        }

        for (string str : folder) {
            if (trie.search(str)) {
                res.push_back(str);
            }
        }

        return res;
    }
};