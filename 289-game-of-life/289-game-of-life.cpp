class Solution {
public:
    bool isvalid(int i, int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    int count(int i, int j, int n, int m, vector<vector<int>> &b)
    {
        int ct=0;
        int x[8] = {-1, 1, 1, -1, 1, 0, 0, -1};
        int y[8] = {1, -1, 1, 0, 0, -1, 1, -1};
        for(int k=0;k<8 ;k++)
        {
            int xx = i + x[k];
            int yy = j + y[k];
            if(isvalid(xx, yy, n, m) && (b[xx][yy]==1 || b[xx][yy]==2))
            {
                ct++;
            }
        }
        return ct;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ct = count(i, j, n, m, board);
                if((ct< 2 || ct> 3) && board[i][j]==1)
                {
                    board[i][j]=2;  // dead
                }
                else if(ct==3 && board[i][j]==0)
                {
                    board[i][j]=-1;  // alive
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==-1) board[i][j]=1;
            }
        }
    }
};