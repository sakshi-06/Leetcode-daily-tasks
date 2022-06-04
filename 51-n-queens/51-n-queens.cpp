class Solution {
public:
    vector<bool> diag1;
    vector<bool> diag2;
    vector<bool> row;
    vector<bool> col;
    void solve(int n, vector<string> &ans, vector<vector<string>> &res, int r)
    {
       if(r==n) {
           res.push_back(ans);
           return;
       }
        for(int i=0;i<n;i++)
        {
                if(!(diag1[r+i]) && !(row[r]) && !(col[i]) && !(diag2[r-i+n-1]))
                {
                    row[r]=true;
                    col[i]=true;
                    diag1[r+i]=true;
                    diag2[r-i+n-1]=true;
                    ans[r][i]='Q';
                    solve(n , ans, res, r+1);
                    row[r]=false;
                    col[i]=false;
                    diag1[r+i]=false;
                    diag2[r-i+n-1]=false;
                    ans[r][i]='.';
                }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        row.resize(n, false);
        col.resize(n, false);
        diag1.resize(2*n-1, false);
        diag2.resize(2*n-1, false);
        vector<string> ans(n, string(n , '.'));
        vector<vector<string>> res;
        solve(n, ans, res, 0);
        return res;
        
    }
};