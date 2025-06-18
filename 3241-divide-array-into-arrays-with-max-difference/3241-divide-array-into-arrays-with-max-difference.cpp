class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        int parts = n/3;

        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        int l=0,r=2;
        while(r<n){
            vector<int>temp;
            if(nums[r]-nums[l] <= k){
                for(int i=l;i<=r;i++){
                    temp.push_back(nums[i]);
                }
                l += 3;
                r += 3;
                ans.push_back(temp);
            }else{
                l++;
                r++;
            }
        }
        if(ans.size() != parts) return {};
        else return ans;
    }
};