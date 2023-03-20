class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        for(int i=0;i<s;i++)
        {
            if(flowerbed[i]==1)
            {
                continue;
            }
            else
            {
                if((i==0||flowerbed[i-1]==0)&&(i==flowerbed.size()-1|| flowerbed[i+1]==0))
                {
                    n--;
                    flowerbed[i]=1;
                }
            }
        }
        return n<=0;
    }
};