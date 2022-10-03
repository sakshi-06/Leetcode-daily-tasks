class Solution {
public:
    int minCost(string s, vector<int>& cost) {
       int co=0;
        for(int i=0;i<s.size();i++)
        {
            int sum=cost[i];
            int maxi=cost[i];
            int cnt=1;
            while(i<s.size() && s[i]==s[i+1])
            {
                sum+=cost[i+1];
                maxi=max(maxi, cost[i+1]);
                cnt++;
                i++;
            }
            if(cnt>1)
            {
                co+=sum-maxi;
            }
            
        }
        return co;
    }
};