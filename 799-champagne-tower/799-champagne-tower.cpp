class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double cups[102][102]={0.0};
        cups[0][0]=(double)poured;
        for(int r=0;r<=query_row;r++)
        {
            for(int c=0;c<=r;c++)
            {
                double q=(cups[r][c]-1.0)/2.0;
                if(q>0)
                {
                    cups[r+1][c]+=q;
                    cups[r+1][c+1]+=q;
                }
            }
        }
        return min(1.0,cups[query_row][query_glass]);
        
    }
};