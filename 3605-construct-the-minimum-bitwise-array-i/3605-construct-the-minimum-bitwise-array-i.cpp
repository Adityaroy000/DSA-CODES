class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0 ;i<n;i++){
            int num = nums[i];
            bool flag = false;
            for(int x = 0;x<=num;++x){
                if((x|(x+1))==num){
                    ans.push_back(x);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};