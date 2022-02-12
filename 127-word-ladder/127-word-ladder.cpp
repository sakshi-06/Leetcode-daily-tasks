class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        q.push(beginWord);
        int dist=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                string temp=q.front();
                q.pop();
                if(temp==endWord) return dist;
                for(int i=0;i<temp.size();i++)
                {
                    string neww=temp;
                    for(char j='a';j<='z';j++)
                    {
                        neww[i]=j;
                        if(st.find(neww)!=st.end())
                        {
                            q.push(neww);
                            st.erase(neww); //imp
                        }
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};