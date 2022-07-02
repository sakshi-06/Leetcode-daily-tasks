class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        ho.push_back(0);
        ho.push_back(h);
        ve.push_back(0);
        ve.push_back(w);
        sort(ho.begin(), ho.end());
        sort(ve.begin(), ve.end());
        int mx=0, my=0;
        for(int i=0;i<ho.size()-1;i++)
        {
            my=max(my,ho[i+1]-ho[i]);
        }
        for(int i=0;i<ve.size()-1;i++)
        {
            mx=max(mx,ve[i+1]-ve[i]);
        }
        return (long) mx * my%1000000007;
    }
};