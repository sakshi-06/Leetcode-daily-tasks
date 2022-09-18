class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto start=products.begin();
        sort(start,products.end());
        vector<vector<string>>ans;
        vector<string>temp;
        string curr="";
        for(auto c:searchWord){
            curr+=c;
            temp.clear();                       //upto this same as previous code
            start=lower_bound(start,products.end(),curr);      // providing first occurance
            for(int i=0;i<3 && start+i!=products.end();i++){         //question asked 3 times so i<3 and start+i!=products.end() -> checks if we are out of index or not
                string s=*(start+i);        //(start+i) gives the pointer and *(start+i) gives the value at the pointer->here string
                if(s.find(curr))break;         //if we dont find the curr then we are sure that we are not going to find it in the upcoming words as they are in sorted manner
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};