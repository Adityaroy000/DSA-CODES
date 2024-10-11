class StockSpanner {
    vector<int>arr;
    int i = -1;
    stack<int>st;
    int cnt = 1;
public:
    StockSpanner() {
        arr={};
    }
    int next(int price) {
        arr.push_back(price);
        i++;
        while(!st.empty()&&arr[st.top()]<=price){
            st.pop();
        }
        if(!st.empty()){
            cnt = i-st.top();
        }
        else{
            cnt = i-(-1);
        }
        st.push(i);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */