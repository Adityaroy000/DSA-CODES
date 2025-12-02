class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        unordered_map<int,int>mpp;
        vector<int>temp;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            if(cnt>0){
                mpp[i] = cnt;
                temp.push_back(i);
            }
        }

        int ans = 0;
        if(temp.empty()) return 0;
        for(int i=0;i<temp.size()-1;i++){
            ans += (mpp[temp[i]]*mpp[temp[i+1]]);
        }
        return ans;
    }
};