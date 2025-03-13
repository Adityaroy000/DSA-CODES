class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxlen = 0;
        int l =0,r = 0;
        int hash[26] = {0},maxfreq = 0;
        while(r<n){
            hash[s[r]-'A'] ++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            int change = (r-l+1)- (maxfreq);
            if(change<=k){
                maxlen = max(maxlen,r-l+1);
            }else {
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }
        
        return maxlen;
    }
};