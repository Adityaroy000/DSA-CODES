class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>copy = nums;
        sort(copy.begin(),copy.end());
        int n = nums.size();
        vector<int>temp(n,0);
        for(int x = 1; x<=n; x++){
            for(int i = 0;i<n; i++){
                temp[i] = nums[(i+x)%n];
            }
            if(temp == copy) return true;
        }
        return false;
    }
};