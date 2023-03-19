class WordDictionary {
public:
    struct trie
    {
      trie* children[26];
        bool isEnd;
        trie()
        {
            for(int i=0;i<26;i++)
            {
                children[i]=nullptr;
            }
            isEnd=false;
        }
    };
    trie* curr;
    WordDictionary() {
        curr=new trie();
    }
    
    void addWord(string word) {
        trie* node=curr;
        for(auto &w:word)
        {
            int index=w-'a';
            if(node->children[index]==nullptr)
            {
                node->children[index]=new trie();
            }
            node=node->children[index];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
         trie *node  = curr;
        return helper(word,node,0);
    }
    bool helper(string word, trie* root, int index){
        if(index==word.size()) return root->isEnd; // return true if the last node is marked as the end of a word
        trie* node=root;
        char c=word[index];
        int idx=c-'a';
        if(c=='.'){   // if character is '.' check for remaining characters in all nodes
            for(int i=0;i<26;i++){
                if(node->children[i]){
                   bool search= helper(word,node->children[i],index+1); 
                   if(search) return true;
                }
            }
            return false;
        }
        else{
            if(!node->children[idx])return false; // if the current character doesn't exist return false
            return helper(word,node->children[idx],index+1); // if current character exists check for remaining characters
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */