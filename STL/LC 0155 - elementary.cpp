/*
155. Min Stack
*/

class MinStack {
public:
    
    vector<int> S;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        S.push_back(val);
    }
    
    void pop() {
        S.pop_back();
    }
    
    int top() {
        return S.back();
    }
    
    int getMin() {
        int minn = INT_MAX;
        for(int i =0;i<S.size();i++)
            minn = S[i] < minn ? S[i] : minn;
        return minn;
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