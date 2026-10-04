class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();

        // as diving by 2 can give either 0 or 1 as remainder so instead of a map , we took two varibale;
        int even_cnt = 1; // before index 0 , psum is 0 which is even
        int odd_cnt = 0;

        int psum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            psum += arr[i];

            if(psum % 2 != 0){ // if psum is odd that means we need even prefix sum so that odd-even_sum = odd sum subarray.
                cnt = (cnt+even_cnt)%mod;
                odd_cnt++;
            }else{ // if psum is even that means we need odd prefix sum so that even-odd = odd sum subarray.
                cnt = (cnt+odd_cnt)%mod;
                even_cnt++;
            }
        }

        return cnt;
    }
};