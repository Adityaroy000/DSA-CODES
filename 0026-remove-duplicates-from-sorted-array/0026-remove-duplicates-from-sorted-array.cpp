class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i=1;
        int size = n;
        while(i<size){
            if(nums[i]==nums[i-1]){
                for(int j = i;j<size-1;j++){
                    nums[j] = nums[j+1];
                }
                size--;
            }else{
                i++;
            }
        }
        int cnt = 0;
        for(int i=0;i<size-1;i++){
            if(nums[i] != nums[i+1]) cnt++;
            else break;
        }
        return cnt+1;
    }
};