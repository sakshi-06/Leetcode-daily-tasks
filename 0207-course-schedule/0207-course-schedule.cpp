class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dependency hai to topo sort
        vector<int> indegree(numCourses+1, 0);
        vector<vector<int>> graph(numCourses);
        for(auto &p:prerequisites){
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        queue<int> q;
        vector<int> vis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k = q.front();
            q.pop();
            vis[k]=1;
            for(auto &n:graph[k]){
                indegree[n]--;
                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};