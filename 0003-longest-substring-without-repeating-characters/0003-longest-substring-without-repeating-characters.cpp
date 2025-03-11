class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int maxlen = 0;
        int l = 0,r = 0;
        unordered_map<char,int>mpp;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                l = max(l,mpp[s[r]]+1);
            }
            maxlen = max(maxlen, r-l+1);
            mpp[s[r]] = r; 
            r++;
        }
        return maxlen;
    }
};