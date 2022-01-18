class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        vector<bool> pos(s,true);
        for(int i=0;i<s;i++)
        {
            if(flowerbed[i]==1)
            {
                continue;
                // if(i>0) pos[i-1]=false;
                // if(i<s-1) pos[i+1]=false;
                // pos[i]=false;
                
            }
           if ((i == 0 || flowerbed[i - 1] == 0) && (i == size(flowerbed) - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1; --n;
            }
        }
        
        return n<=0;
    }
};