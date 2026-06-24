class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int>mpp;
        for(int x : arr){
            mpp[x]++;
        }

        int ans = INT_MIN;
        for(int x : arr){
            if(mpp.count(x) && mpp[x] == x){
                ans = max(ans,x);
            }
        }
        return ans == INT_MIN?-1:ans;
    }
};