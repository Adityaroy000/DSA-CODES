class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0 ;
        vector<int>pre(n+1);
        /*
        replace 0 by -1
        then we need to find the max length of subarray whose sum = 0
        So, for a subarray: [pi,pi+1,pi+2,pi+3,...,pj]
        sum = prefix[j] - prefix[i-1]
        as sum = 0, so prefix[j] == prefix[i-1]
        so you got the index of both then just find the length and compare with max
        */

        int prefix = 0;

        unordered_map<int,int>mpp; //val,idx
        mpp[0] = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) prefix -= 1;
            else prefix += 1;
            if(mpp.find(prefix)==mpp.end()) mpp[prefix] = i;
            else{
                maxi = max(maxi,i-mpp[prefix]);
            }
        }
        return maxi;
    }
};