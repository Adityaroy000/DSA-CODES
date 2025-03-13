class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0,cnt=0;
        int ocnt = 0,cntf=0,cntk=0,focc =-1,fkocc=-1;
        while(r<n){
            if(nums[r]%2!=0){
                cnt++;
                if(cntf<1) focc = r;
                cntf++;
            }
            while(cnt>k){
                if(nums[l]%2!=0){
                    cnt--;
                    l++;
                    focc = l;
                }else{
                    l++;
                }
            }
            if(cnt == k){
                while(nums[focc]%2==0) focc++;
                ocnt += focc - l+1;
            }
            r++;
        }
        return ocnt;
    }
};