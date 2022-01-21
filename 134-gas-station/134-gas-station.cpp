class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n=gas.size();
        int cap=0, due=0,start=0;
        for(int i=0;i<n;i++)
        {
           cap += gas[i]-cost[i];
            if(cap<0)
            {
                start=i+1; 
                
                due+=cap;
                cap=0;
            }
            
        }
        return due+cap >=0?start:-1;
    }
};