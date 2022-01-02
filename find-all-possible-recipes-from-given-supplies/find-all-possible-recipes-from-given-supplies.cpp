class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
         map<string, int> indegree;
       map<string, vector<string>> adj;
        for (int i = 0; i < ingredients.size(); i++)
        {
            for (string ing : ingredients[i])
            {
                adj[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        vector<string> ans;
    
        for(string item : supplies)
            if(indegree[item] == 0)
                q.push(item);

        while(!q.empty())
        {
            string item = q.front();
            q.pop();
            for(string recipe : adj[item])
            {
                if(--indegree[recipe] == 0)
                {
                    q.push(recipe);
                     ans.push_back(recipe);
                }
            }
        }
        return ans;
    }
        
};