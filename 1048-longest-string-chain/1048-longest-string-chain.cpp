class Solution {
public:
    vector<vector<int>> edges;
    vector<int> count;
    int longest(int v)
    {
        if(count[v]>0) return count[v];
        count[v]=1;
        for(int b:edges[v])
        {
            count[v]=max(count[v], longest(b)+1);
        }
        return count[v];
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        edges.clear();
        edges.resize(n);
        count.clear();
        count.resize(n,0);
        unordered_map<string , int> m;
        for(int i=0;i<n;i++)
        {
            m[words[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                string check=s.substr(0,j)+s.substr(j+1);
                auto it=m.find(check);
                if(it==m.end())
                {
                    continue;
                }
                edges[it->second].push_back(i);
            }
        }
        int answer=0;
        for(int i=0;i<n;i++)
        {
            answer=max(answer, longest(i));
        }
        return answer;
    }
};