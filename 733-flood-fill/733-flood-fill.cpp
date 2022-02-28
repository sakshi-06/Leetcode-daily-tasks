class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int newColor,int curr)
    {
        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=curr)
        {
            return ;
        }
        image[i][j]=-newColor;
        dfs(image,i+1,j,newColor,curr);
        dfs(image,i-1,j,newColor,curr);
        dfs(image,i,j+1,newColor,curr);
        dfs(image,i,j-1,newColor,curr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,newColor,image[sr][sc]);
        for(int i=0;i<image.size();i++)
        {
            for(int j=0;j<image[i].size();j++)
            {
                if(image[i][j]<0) image[i][j]=-image[i][j];
            }
        }
        return image;
    }
};