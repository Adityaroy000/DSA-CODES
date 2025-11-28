class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int k = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                k = i;
                break;
            }
        }
        if(k==-1) return n;
        int idx = k;
        while(idx<n && nums[idx]==val){
            idx++;
        }

        while(idx<n){
            nums[k++] = nums[idx++];
        }

        return k;
    }
};