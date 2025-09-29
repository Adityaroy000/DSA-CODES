class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int og = num;
        long long mod = 1;
        for(int i=1;i<=k;i++){
            mod *= 10;
        }
        int cnt =0;
        while(num >= mod/10){
            int div = num%mod;
            if(div != 0 && og % div == 0) cnt++;
            num /= 10;
        }
        return cnt;
    }
};