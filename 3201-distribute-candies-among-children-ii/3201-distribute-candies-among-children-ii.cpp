class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int mini =  max(0,n-(2*limit));
        int maxi =  min(n,limit);

        for(int i = mini;i<=maxi;i++){
            int leftCandy = n-i;
            int miniforch2 = max(0,leftCandy-limit);
            int maxiforch2 = min(leftCandy,limit);

            ways +=(maxiforch2-miniforch2+1);
        }

        return ways;
    }
};