class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = INT_MAX;
        int ans = 0;

        while(low<=high){
            long long mid = low+(high-low)/2;

            long long sum = (mid*(mid+1))/2;

            if(sum == n) return mid;
            else if(sum > n) {
                high = mid-1;
            }else {
                ans = mid;
                low = mid+1;
            }
        }

        return ans;
    }
};