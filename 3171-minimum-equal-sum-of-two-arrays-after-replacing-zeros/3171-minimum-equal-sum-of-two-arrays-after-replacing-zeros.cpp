class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0,cnt1=0;
        long long sum1=0;
        while(i<n1){
            if(nums1[i]==0) {
                cnt1++;
                sum1+=1;
            }
            else sum1+=nums1[i];
            i++;
        }
        long long sum2=0;
        int cnt2=0;
        i=0;
        while(i<n2){
            if(nums2[i]==0) {
                cnt2++;
                sum2+=1;
            }
            else sum2+=nums2[i];
            i++;
        }
        if(sum1<sum2 && cnt1 == 0) return -1;
        else if(sum2<sum1 && cnt2 == 0) return -1;

        return max(sum1,sum2);
    }
};