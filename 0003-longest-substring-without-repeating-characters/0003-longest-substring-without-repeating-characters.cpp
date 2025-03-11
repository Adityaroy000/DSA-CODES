class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int maxlen = 0;
        int l = 0,r = 0;
        int hasmap[256];
        fill(hasmap, hasmap + 256, -1);
        while(r<n){
            if(hasmap[s[r]] != -1){
                if(hasmap[s[r]]>=l){
                    l = hasmap[s[r]]+1;
                }
            }
            maxlen = max(maxlen, r-l+1);
            hasmap[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};