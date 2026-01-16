class Solution {
public:
    int reverseBits(int n) {
        /*
        we will take last bit of n and then make some space in our "ans" and then just do
        ans|bit. for taking last bit we do N&1;
        */

        int ans = 0;
        for(int i=0;i<32;i++){
            int bit = n&1;
            ans = ans << 1;
            ans = ans | bit;
            n = n>>1;
        }
        return ans;
    }
};