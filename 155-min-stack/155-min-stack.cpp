class MinStack {
public:
    stack<pair<int,int>> st;
    int minele=0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push({val,val});
        }
        else
        {
            int k=st.top().second;
            if(val<k)
            {
                st.push({val,val});
            }
            else
            {
                st.push({val,k});
            }
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */