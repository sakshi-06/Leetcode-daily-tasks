class Solution {
public:
    int mod=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& o) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> sell;
        for(int i=0;i<o.size();i++)
        {
            if(o[i][2]==0)
            {
                buy.push(o[i]);
            }
            else sell.push(o[i]);
            while(buy.size() && sell.size() && buy.top()[0]>=sell.top()[0])
            {
                int k=min(buy.top()[1],sell.top()[1]);
                vector<int> temp=buy.top();buy.pop();
                temp[1]-=k;
                if(temp[1]) buy.push(temp);
                temp=sell.top();
                sell.pop();
                temp[1]-=k;
                if(temp[1]) sell.push(temp);
            }
        }
        int ans=0;
        while(!buy.empty())
        {
            ans=(ans+buy.top()[1])%mod;
            buy.pop();
        }
        while(!sell.empty())
        {
            ans=(ans+sell.top()[1])%mod;
            sell.pop();
        }
        return ans;
    }
};