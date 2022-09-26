class Solution {
public:
    int find_par(int i, vector<int> parent)
    {
        if(parent[i]==i) return i;
        return find_par(parent[i], parent);
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++)
        {
            
            if(equations[i][1]=='=')
            {
                int p1=find_par(equations[i][0]-'a', parent);
                 int p2=find_par(equations[i][3]-'a', parent);
                parent[p1]=p2; 
            }
           
        }
        for(int i=0;i<equations.size();i++)
        {
            int p1=find_par(equations[i][0]-'a', parent);
            int p2=find_par(equations[i][3]-'a', parent);
            if(equations[i][1]=='!')
            {
                if(p1==p2)
                {
                    return false;
                }
            }
            
        }
    return true;
    }
};