class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void bfs(vector<vector<char>> &b, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        b[i][j] = 'o';
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int n_x = x+ dir[k][0];
                int n_y = y+ dir[k][1];
                if(n_x>=0 && n_y >=0 && n_x<b.size() && n_y<b[0].size() && b[n_x][n_y]=='O'){
                    b[n_x][n_y] = 'o';
                    q.push({n_x, n_y});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&& (i==0 || j==0 || i==n-1 || j==m-1)){
                    bfs(board, i, j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='o'){
                    board[i][j] = 'O';
                } else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};