class DataStream {
public:
    int val,m;
    int cnt = 0;
    DataStream(int value, int k) {
        val = value;
        m= k;
    }
    
    bool consec(int num) {
        if(num == val) cnt++;
        else cnt = 0;

        if(cnt >= m) return true;
        return false; 
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */