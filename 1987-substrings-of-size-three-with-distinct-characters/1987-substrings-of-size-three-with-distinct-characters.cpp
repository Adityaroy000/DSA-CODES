class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();

        if(n<3) return 0;
        int cnt = 0;
        for(int i=1;i<n-1;i++){
            if(s[i-1] != s[i] && s[i] != s[i+1] && s[i-1] != s[i+1]) cnt++;
        }
        
        return cnt;
    }
};