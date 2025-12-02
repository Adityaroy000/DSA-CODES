class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0; // to track devices in prev row
        int ans = 0;

        /*
        Count devices in each row.
        Keep only rows where count > 0.
        For each pair of consecutive such rows, add:
        devices_in_row[i] * devices_in_row[i+1].
        */
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }
            }
            if(cnt>0){
               if(prev>0) ans += prev*cnt;
               prev = cnt;
            }
        }

        return ans;
    }
};