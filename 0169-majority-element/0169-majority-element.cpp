class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int el;
        for(int i = 0;i<n; i++){
            if(count == 0){
                count = 1;
                el = nums[i];
            }else if(el == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(el == nums[i]) cnt++;
        }
        if(cnt>(n/2)) return el;
        return -1;
    }
};