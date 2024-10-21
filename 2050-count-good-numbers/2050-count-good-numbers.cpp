class Solution {
public:
    int mod = 1e9+7;
    long long Pow(long long x , long long n){
        if(n==0) return 1;
        long long half = Pow(x,n/2)%mod;
        if(n%2==0) return (half*half)%mod;
        else return (((half*half)%mod)*x)%mod;
    }
    int countGoodNumbers(long long n) {
        long long evenpos = (n+1)/2;
        long long oddpos = n/2;
        long long ans1 = Pow(5,evenpos)%mod;
        long long ans2 = Pow(4,oddpos)%mod;
        long long ans = (ans1*ans2)%mod;
        return ans;
    }

};