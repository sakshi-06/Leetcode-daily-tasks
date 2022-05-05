class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    int peek=-1;
    MyStack() {
        
    }
    
    void push(int x) {
        peek=x;
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1)
        {
            int x=q1.front();
            peek=x;
            q2.push(x);
            q1.pop();
        }
        int k=q1.front();
        q1.pop();
        swap(q1,q2);
        return k;
    }
    
    int top() {
        return peek;;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */