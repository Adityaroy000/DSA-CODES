class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                if(i%2 != 0) cnt++;

                int odiv = n/i;

                if(i*i != n){
                    if(odiv%2 != 0) cnt++;
                }
            }
        }
        return cnt;
    }
};