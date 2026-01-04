class Solution {
public:
    int check(int num){
        int sum = 0;
        int cnt = 0;
        for(int i=1;i*i<=num;i++){
            if(cnt > 4) return 0;
            if(num%i == 0) {
                int fd = i;
                int sd = num/i;
                if(sd != fd){
                    sum += fd+sd;
                    cnt += 2;
                }else{
                    sum += fd;
                    cnt++;
                }
            }
        }
        if(cnt == 4){
            return sum;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int ans = check(nums[i]);
            if(ans != 0){
                sum += ans;
            }
        }
        return sum;
    }
};