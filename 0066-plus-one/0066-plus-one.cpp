class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>res(n+1);

        int ld = digits[n-1]+1;
        digits[n-1] = ld%10;
        int carry = ld/10;

        int i = n-2;
        while(i>= 0 && carry == 1){
            int nd = digits[i]+carry;
            digits[i] = nd%10;

            carry = nd/10;
            i--;
        }

        if(carry == 1){
            res[0] = 1;
            for(int i=0;i<n;i++) res[i+1] = digits[i];
            return res;
        }
        return digits;
    }
};