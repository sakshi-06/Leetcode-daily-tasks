class Solution {
public:
    void check(vector<vector<char>> &grid, int i, int j, int row, int col)
    {
        if(i<0 || i>=row|| j<0 ||j>=col || grid[i][j]!='1')
            return;
        grid[i][j]='2';
        check(grid,i+1,j,row, col);
        check(grid,i-1,j,row, col);
        check(grid,i,j+1,row, col);
        check(grid,i,j-1,row, col);
    }
    int numIslands(vector<vector<char>>& grid) {
       if(grid.size()==0) return 0;
        int row=grid.size();
        int count=0;
        int col= grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    check(grid, i, j, row, col);
                }
            }
        }
        return count;
    }
};