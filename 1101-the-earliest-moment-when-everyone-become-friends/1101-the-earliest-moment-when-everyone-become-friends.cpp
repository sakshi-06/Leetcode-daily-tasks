class Solution {
public:
    vector<int> parent, size;
    void merge(int p, int q){
        if(size[p]>size[q]){
            parent[q]=p;
            size[p]+=size[q];
        } else{
            parent[p]=q;
            size[q]+=size[p];
        }
    }
    int find_parent(int p){
        if(parent[p]==p) return p;
        return parent[p]=find_parent(parent[p]);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        parent.resize(n,-1);
        for(int i=0;i<n;i++) parent[i]=i;
        size.resize(n,1);
        for(int i=0;i<logs.size();i++){
            int t = logs[i][0];
            int p = logs[i][1];
            int q = logs[i][2];
            int parent_p=find_parent(p);
            int parent_q=find_parent(q);
            if(parent_p != parent_q){
                merge(parent_p,parent_q);
                if(size[parent_p] == n|| size[parent_q] == n){
                    return t;
                }
            }
        }
        return -1;
    }
};