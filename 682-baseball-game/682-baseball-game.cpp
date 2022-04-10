class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto z: ops)
        {
            if(z=="C")
            {
                s.pop();
            }
            else if(z=="+")
            {
                int x=s.top();
                s.pop();
                int y=s.top();
                int sum=x+y;
                s.push(x);
                s.push(sum);
            }
            else if(z=="D")
            {
                s.push(2*s.top());
            }
            else 
            {
                s.push(std::stoi(z));
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
    }
};