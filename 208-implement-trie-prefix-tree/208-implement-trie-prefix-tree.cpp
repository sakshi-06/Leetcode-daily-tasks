class Trie {
public:
    struct trieNode{
      struct trieNode* children[26];
        bool isEnd;
        trieNode()
        {
            for(int i=0;i<26;i++)
            {
                children[i]=nullptr;
            }
            isEnd=false;
        }
    };
    trieNode* node;
    
    Trie() {
        node = new trieNode;
    }
    
    void insert(string word) {
        trieNode* curr=node;
        for(auto &c:word)
        {
            int index=c-'a';
            if(curr->children[index]!=nullptr)
            {
                curr=curr->children[index];
            }
            else
            {
                curr->children[index]=new trieNode;
                curr=curr->children[index];
            }
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
       trieNode* curr=node;
        for(auto c:word)
        {
            int index=c-'a';
            if(curr->children[index]==nullptr) return false;
            curr=curr->children[index];
        }
        return curr->isEnd==true;
    }
    
    bool startsWith(string prefix) {
        trieNode* curr=node;
        for(auto c:prefix)
        {
            int index=c-'a';
            if(curr->children[index]==nullptr) return false;
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