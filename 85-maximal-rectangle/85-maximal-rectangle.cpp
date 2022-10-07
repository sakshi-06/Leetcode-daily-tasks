class Solution {
public:
    int solve(vector<int>&v)
    {
        stack<int>st;
        int n=v.size();
        vector<int> right(n,n);
        vector<int> left(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && v[st.top()]>=v[i])
            {
                st.pop();
            }
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && v[st.top()]>=v[i])
            {
                st.pop();
            }
            if(!st.empty()) right[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, (right[i]-left[i]-1)*v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0) return 0;
        vector<int> v(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    v[j]+=1;
                }
                else v[j]=0;
            }
            ans=max(ans,solve(v));
        }
        return ans;
    }
};