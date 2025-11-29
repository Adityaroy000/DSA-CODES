class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maxi = 0;
        
        char ch = '#';
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=ch){
                ch = s[i];
                cnt = 1;
            }else cnt ++;
            maxi = max(maxi,cnt);
        }
        
        return maxi;
    }
};