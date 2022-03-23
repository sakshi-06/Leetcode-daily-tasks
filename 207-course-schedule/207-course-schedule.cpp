class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        vector<int> e(n,0);
        int cnt=0;
        queue<int> q;
        for(auto x:p)
        {
            v[x[1]].push_back(x[0]);
            e[x[0]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(e[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<v[temp].size();i++)
            {
                e[v[temp][i]]--;
                if(e[v[temp][i]]==0) q.push(v[temp][i]);
            }
        }
        if(cnt==n) return true;
        return false;
    }
};