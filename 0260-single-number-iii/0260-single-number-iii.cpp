class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        for(int num:nums){
            xorAll ^= num;
        }
        /*
        Find a bit where they differ
        We need to separate numbers into two groups:
            group containing a
            group containing b
        Use a bit where a and b differ.
        From xorAll, pick any set bit.
        Now split numbers into two groups:
        Group 1 → bit is 1
        Group 2 → bit is 0
        */
        long bit = xorAll & (-(long)xorAll);
        int xor1 = 0,xor2=0;
        for(int num:nums){
            if(num&bit){
                xor1 ^= num;
            }else{
                xor2 ^= num;
            }
        }

        return {xor1,xor2};
    }
};