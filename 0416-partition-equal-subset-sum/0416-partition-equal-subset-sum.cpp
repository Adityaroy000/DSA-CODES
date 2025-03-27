class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2 != 0) return false;
        int ts = sum/2;
        vector<bool>prev(sum+1,false);
        prev[0] = true;
        prev[arr[0]] = true;
        //Fill dp table
        for(int i=1;i<n;i++){
            vector<bool>curr(ts+1,false);
            curr[0] = true;
            for(int j=1;j<=ts;j++){//j->target
                bool nottake = prev[j];
                bool take = false;
                if(arr[i]<=j){
                    take = prev[j-arr[i]];
                }
                curr[j] = take||nottake;
            }
            prev = curr;
        }
        
        return prev[ts];
    }
};