class Solution {
public:
    int maximumSwap(int num) {
        int temp = num;
        vector<int>ans;
        while(num>0){
            int digits = num%10;
            ans.push_back(digits);
            num = num/10;
        }
        int n = ans.size(),idx1,maxi;
        int cnt = 0;
        for(int i = 0; i<n-1;i++){
            if(ans[i+1]<ans[i]){
                cnt = 1;
                break;
            }
        }
        if(cnt == 0) return temp;
        for(int i = n-1;i>=0; i--){
            idx1 = -1,maxi = -1;
            for(int j= i-1; j>=0;j--){
                if(ans[j]>=maxi) {
                    maxi = ans[j];
                    idx1 = j;
                }
            }
            if(idx1!= -1 && ans[idx1]>ans[i]){
                swap(ans[i],ans[idx1]);
                break;
            }
        }
        int sum = 0;
        for(int i = n-1; i>=0;i--){
            sum = sum+(ans[i]*(int)pow(10,i));
        }
        return sum;
    }
};