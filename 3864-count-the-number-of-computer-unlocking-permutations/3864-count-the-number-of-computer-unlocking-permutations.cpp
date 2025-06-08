class Solution {
public:
    int mod = 1e9+7;
    long long fact(int n){
        long long prod = 1;
        for(int i=2;i<=n;i++){
            prod = (prod*i)%mod;
        }
        return prod%mod;
    }
    long long countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        int val = complexity[0];

        for(int i=1;i<n;i++){
            if(complexity[i]<=val) {
                return 0;
            }
        }
        return fact(n-1)%mod;
    }
};