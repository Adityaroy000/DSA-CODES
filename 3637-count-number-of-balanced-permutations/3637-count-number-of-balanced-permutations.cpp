class Solution {
public:
    int n;
    long long totalPermutposs = 0;
    int m = 1e9+7;
    int totalSum = 0;

    int findPower(long long a,long long b){
        if(b==0) return 1;
        long long half = findPower(a,b/2);
        long long res = (half*half) % m;
        if(b%2==1){
            res = (res*a)%m;
        }
        return res;
    }

    int solve(int digit,vector<int>& freq,vector<long long>& fermatfact,int evenidxdigitcount,int currsum,vector<vector<vector<int>>>& dp){
        if(digit == 10){
            if(evenidxdigitcount == (n+1)/2 && currsum == totalSum/2){
                return totalPermutposs;
            }
            return 0;
        }

        if(dp[digit][evenidxdigitcount][currsum] != -1) return dp[digit][evenidxdigitcount][currsum];

        long long ways = 0;
        for(int count = 0;count<=min(freq[digit],(n+1)/2 - evenidxdigitcount);count++){
            int evenPosCount = count;
            int oddPosCount = freq[digit]-count;

            long long div = (fermatfact[evenPosCount]*fermatfact[oddPosCount])%m;
            long long val = solve(digit+1,freq,fermatfact,evenidxdigitcount+evenPosCount,currsum+digit*count,dp);
            ways = (ways +( val*div)%m)%m;
        }
        return dp[digit][evenidxdigitcount][currsum] = ways;
    }
    int countBalancedPermutations(string num) {
        n = num.length();
        vector<int>freq(10,0);
        for(int i = 0;i<n;i++){
            freq[num[i]-'0']++;
            totalSum += num[i]-'0';
        }

        if(totalSum % 2!=0) return 0;


        //precompute factorial
        vector<long long> fact(n+1,1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2;i<=n;i++){
            fact[i] = (fact[i-1]*i)%m;
        }
        totalPermutposs = (1LL*fact[(n+1)/2]*fact[n/2])%m;
        //precompute fermat factorial
        vector<long long>fermatfact(n+1,1);
        for(int i = 0;i<=n;i++){
            fermatfact[i] = findPower(fact[i],m-2)%m;
        }

        int digit = 0;
        int evenidxdigitcount = 0;
        int currsum = 0;
        vector<vector<vector<int>>>dp(10,vector<vector<int>>((n+1)/2 + 1,vector<int>(totalSum+1 , -1)));
        return solve(digit,freq,fermatfact,evenidxdigitcount,currsum,dp);

    }
};