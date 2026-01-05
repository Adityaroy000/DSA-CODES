class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        int prefixXor = 0;
        int prefixParity = 0; //if event add +1 if odd add -1
        unordered_map<long long,int>mpp;
        mpp[0LL] = -1;
        int len = 0;

        for(int i=0;i<n;i++){
            prefixXor ^= nums[i];
            
            if(nums[i]%2==0) prefixParity++;
            else prefixParity--;

            long long key = key = ((long long)prefixXor << 32) | (prefixParity & 0xffffffff);
            if(mpp.count(key)){
                len = max(len,(i-mpp[key]));
            }
            else mpp[key] = i;
        } 

        return len;
    }
};