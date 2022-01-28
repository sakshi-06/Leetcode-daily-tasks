class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trieNode{
      struct trieNode* child[26];
        bool isEnd;
        trieNode()
        {
            for(int i=0;i<26;i++) child[i]=nullptr;
            isEnd = false;
        }
    };
    trieNode *node;
    WordDictionary() {
        node = new trieNode();
    }
    
    void addWord(string word) {
        trieNode* curr=node;
        for(auto c:word){
            int  index=c-'a';
            if(curr->child[index]==nullptr)
            {
                curr->child[index]=new trieNode();
            }
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
       return searchHelper(word, node); 
    }
    bool searchHelper(string word, trieNode* current) {
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch != '.'){
                if(!current->child[ch - 'a']) 
                    return false;
                current = current->child[ch - 'a'];
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(current->child[j] && searchHelper(word.substr(i + 1), current->child[j])){
                        return true;
                    }
                }
                return false;
            }
        }
        return current->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */