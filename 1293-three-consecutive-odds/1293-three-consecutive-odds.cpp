class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();

        int l=0,r=0,cnt=0;
        while(r<n){
            if(arr[r]%2!=0) cnt++;
            else {
                cnt = 0;
            }
            if(cnt==3) return true;

            r++;
        }
        return false;
    }
};