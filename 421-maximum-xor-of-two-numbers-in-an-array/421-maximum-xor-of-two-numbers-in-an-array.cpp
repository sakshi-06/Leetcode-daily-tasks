class Solution {
public:
    struct trie{
	trie *child[2];
	trie()
	{
		child[0]=nullptr;
		child[1]=nullptr;
	}
};
trie* root;
void insert(int n)
{
	trie* curr=root;
	for(int i=31;i>=0;i--)
	{
		int bit=(n>>i)&1;
		if(curr->child[bit]==nullptr)
		{
			curr->child[bit]=new trie();
		}
		curr=curr->child[bit];
	}
}
int find_max(int n)
{
	trie* curr=root;
	int ans=0;
	for(int i=31;i>=0;i--)
	{
		int bit=(n>>i)&1;
		if(curr->child[!bit]!=nullptr)
		{
			ans|=(1<<i);
			curr=curr->child[!bit];
		}
		else curr=curr->child[bit];

	}
	return ans;
	

}
    int findMaximumXOR(vector<int>& nums) {
        root=new trie();
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,find_max(nums[i]));
        }
        return ans;
    }
};