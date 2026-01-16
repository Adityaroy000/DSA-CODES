class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lb = n&1;
        n = n>>1;
        bool flag = false;
        while(n!=0){
            int currLastBit = n&1;
            if(currLastBit == lb) return false;
            lb = currLastBit;
            n = n>>1;
        }
        return true;
    }
};