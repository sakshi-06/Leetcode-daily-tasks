class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n= friends.size();
        vector<int> vis(n, -1);
        queue<int> q;
        q.push(id);
        vis[id]=0;
        while(!q.empty())
        {
           int y= q.front();
            q.pop();
            for(auto x:friends[y])
            {
                if(vis[x]!=-1)
                {
                    continue;
                }
                q.push(x);
                vis[x]=vis[y]+1;
            }
        }
        unordered_map<string, int> m;
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==level)
            {
                for(auto x: watchedVideos[i])
                {
                    m[x]++;
                }
            }
        }
        vector<pair<int, string>> v;
        for(auto x:m)
        {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto temp:v)
        {
            ans.push_back(temp.second);
        }
        return ans;
        
    }
};