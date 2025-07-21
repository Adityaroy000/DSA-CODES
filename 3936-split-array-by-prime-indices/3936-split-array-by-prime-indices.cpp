class Solution {
public:
    bool check(int n){
        if(n==0 || n==1) return false;
        if(n==2) return true;
        if(n%2 == 0) return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i == 0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        vector<int>A;
        vector<int>B;

        for(int i=0;i<nums.size();i++){
            if(check(i)){
                A.push_back(nums[i]);
            }else{
                B.push_back(nums[i]);
            }
        }
        long long sumA = accumulate(A.begin(),A.end(),0LL);
        long long sumB = accumulate(B.begin(),B.end(),0LL);

        return abs(sumA-sumB);
    }
};