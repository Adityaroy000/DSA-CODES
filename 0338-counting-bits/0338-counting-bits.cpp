class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        /*
            any binary  number is [some bits] + [last bit]
            so total one = one in [some bits] + one in [last bit]
            i>>1 -> removes last bit from i
            i&1 -> tells if last bit is 1 or 0
        */
        for(int i=0;i<=n;i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};