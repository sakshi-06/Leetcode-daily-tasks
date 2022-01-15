class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        int step=0;
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
           for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = mp[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
            
        }
        return step;
    }
};