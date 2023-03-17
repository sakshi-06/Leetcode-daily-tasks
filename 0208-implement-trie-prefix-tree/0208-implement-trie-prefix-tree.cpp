class Trie {
public:
    struct TrieNode{
        struct TrieNode* children[26];
        bool isEnd;
        TrieNode()
        {
        for(int i=0;i<26;i++)
        {
            children[i]=nullptr;
        }
        isEnd=false;
        }
    };
    TrieNode* node;
    Trie() {
        node=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=node;
        for(auto w:word)
        {
            int index=w-'a';
            if(curr->children[index]!=nullptr)
            {
                curr=curr->children[index];
            }
            else
            {
                curr->children[index]=new TrieNode();
                curr=curr->children[index];
            }
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=node;
        for(auto w:word)
        {
            int index=w-'a';
            if(curr->children[index]==nullptr)
            {
                return false;
            }
            curr=curr->children[index];
        }
        return curr->isEnd==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=node;
        for(auto w:prefix)
        {
            int index=w-'a';
            if(curr->children[index]==nullptr)
            {
                return false;
            }
            curr=curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */