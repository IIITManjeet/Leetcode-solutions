class CustomStack {
public:
    vector<int>st,inc;
    int top=-1;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        inc.resize(maxSize);
        top=-1;
    }
    
    void push(int x) {
        if (top < (int)(st.size()) - 1) {
            st[++top] = x;
        }
    }
    
    int pop() {
        if (top < 0) {
            return -1;
        }
        int result = st[top] + inc[top];
        if (top > 0) {
            inc[top - 1] += inc[top];
        }
        inc[top] = 0;
        top--;
        return result;
    }
    
    void increment(int k, int val) {
        if(top>=0){
            int incInd=min(top,k-1);
            inc[incInd]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */