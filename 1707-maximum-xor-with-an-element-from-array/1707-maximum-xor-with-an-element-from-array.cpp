class Solution {
public:
    struct trie{
        trie* child[2];
        trie()
        {
            child[0]=nullptr;
            child[1]=nullptr;
        }
    };
    trie* root;
    void insert(int x)
    {
        trie* curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(x>>i)&1;
            if(curr->child[bit]==nullptr)
		    {
			    curr->child[bit]=new trie();
		    }
		    curr=curr->child[bit];
        }
    }
    int maxXor(int x)
    {
        trie* curr=root;
	    int ans=0;
	    for(int i=31;i>=0;i--)
	    {
		    int bit=(x>>i)&1;
		    if(curr->child[!bit]!=nullptr)
		    {
			    ans|=(1<<i);
			    curr=curr->child[!bit];
		    }
		    else curr=curr->child[bit];

	    }
	    return ans;
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),cmp);
        root=new trie();
        int j=0;
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++)
        {
            while(j<nums.size() && nums[j]<=queries[i][1])
            {
                insert(nums[j]);
                j++;
            }
            if(j==0) ans[queries[i][2]]=-1;
            else ans[queries[i][2]]=maxXor(queries[i][0]);
            
        }
                return ans;
    }
};