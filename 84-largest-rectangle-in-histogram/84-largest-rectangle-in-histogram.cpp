class Solution {
public:
    void left(vector<int> &nsel, vector<int> &a, int n)
    {
        stack<int> s;
        //s.push(0);
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                s.pop();
            }
            if(!s.empty()) nsel[i]=s.top();
            s.push(i);
        }
    }
    void right(vector<int> &nser, vector<int> &a, int n)
    {
        stack<int> s;
        //s.push(n-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                s.pop();
            }
            if(!s.empty()) nser[i]=s.top();
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        vector<int> nsel(n,-1);
        vector<int> nser(n,n);
        left(nsel, heights, n);
        right(nser, heights, n);
        //for(auto x:ngel) cout<<x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, (nser[i]-nsel[i]-1)*heights[i]);
        }
        return ans;
    }
};