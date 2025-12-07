class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int cntz = 0,cnto = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='1') cnto++;
        }

        int i=0;
        int ans = INT_MIN;
        while(i<n-1){
            if(s[i]=='0'){
                cntz++;
            }else{
                cnto--;
            }
            int score = cntz+cnto;
            ans = max(ans,score);
            i++;
        }
        return ans;
    }
};