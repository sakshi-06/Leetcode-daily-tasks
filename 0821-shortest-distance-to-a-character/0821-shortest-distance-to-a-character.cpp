class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n =s.size();
        
        vector<int> ans(n,n);
        int pos=-n;
        for(int i=0;i<n;i++){
            if(s[i]==c) pos =i;
            ans[i]=i-pos;
        }
        for(int i=pos-1;i>=0;i--){
            if(s[i]==c) pos = i;
            ans[i] = min(ans[i], pos - i);
        }
        return ans;
    }
};