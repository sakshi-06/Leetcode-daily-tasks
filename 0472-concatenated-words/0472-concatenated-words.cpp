class Solution {
public:
    class trieNode{
      public:
        trieNode* children[26];
        bool isend;
        trieNode()
        {
            for(int i=0;i<26;i++) children[i]=nullptr;
            isend=false;
        }
    };
    trieNode* root;
    void insert(string s)
    {
        trieNode* temp=root;
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(!temp->children[index])
            {
                temp->children[index]=new trieNode();
            }
            temp=temp->children[index];
        }
        temp->isend=true;
    }
    bool search(string s)
    {
        trieNode* temp=root;
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(!temp->children[index]) return false;
            temp=temp->children[index];
        }
        return (temp!=nullptr && temp->isend);
    }
    vector<string> ans;
    bool sol(string w, int count)
    {
       if(count>1 && search(w)) return true;
        for(int j=0;j<w.length()-1;j++){
            string left=w.substr(0,j+1);
            string right=w.substr(j+1);
            if(search(left) && sol(right, count+1)) return true;
            
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root= new trieNode();
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]=="") continue;
            insert(words[i]);
        }
        for(auto &w:words)
        {
            if(w=="") continue;
            if(sol(w,1))ans.push_back(w);
        }
        return ans;
    }
};