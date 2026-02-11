class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        for(int num:nums){
            xorAll ^= num;
        }

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