class Solution {
public:
    double knightProbability(int n, int k, int row, int col) {
      vector<vector<double>>pb(n,vector<double>(n,0.0));
      
        if(k==0) return 1.0;
        pb[row][col]=1.0;
        int dir[8][2]={{2,1},{2,-1},{-1,2},{1,-2},{-1,-2},{-2,-1},{-2,1},{1,2}};
        for(;k>0;k--)
        {
             vector<vector<double>>cb(n,vector<double>(n,0.0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int pos=0;pos<8;pos++)
                    {
                        int nr=i+dir[pos][0];
                        int nc=j+dir[pos][1];
                        if(nr>=0 && nc>=0 && nr<n && nc<n)
                        {
                            cb[nr][nc]+=pb[i][j]/8.0;
                        }
                    }
                }
            } 
            pb=cb;
        }
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=pb[i][j];
            }
        }
        return ans;
    }
};