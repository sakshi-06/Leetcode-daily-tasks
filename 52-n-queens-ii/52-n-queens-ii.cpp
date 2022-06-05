class Solution {
public:
    vector<bool> row;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    int solve( int r, int n)
    {
       if(r==n) 
       {
           return 1;
       }
        int count=0;
        for(int c=0;c<n;c++)
        {
            if(row[r]==false && col[c]==false && diag1[r+c]==false && diag2[r-c+n-1]==false)
            {
                row[r]=true;
                col[c]=true;
                diag1[r+c]=true;
                diag2[r-c+n-1]=true;
                count+=solve(r+1, n);
                row[r]=false;
                col[c]=false;
                diag1[r+c]=false;
                diag2[r-c+n-1]=false;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        row.resize(n,false);
         col.resize(n,false);
         diag1.resize(2*n-1,false);
         diag2.resize(2*n-1,false);
        int count=solve(0,  n);
        return count;
    }
};