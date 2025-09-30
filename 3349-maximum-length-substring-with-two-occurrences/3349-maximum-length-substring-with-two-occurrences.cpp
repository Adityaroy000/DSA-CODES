class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>freq(26,0);

        int l=0,r=0;
        int maxlen = 0;
        while(r<n){
            freq[s[r]-'a']++;
           
            while(freq[s[r]-'a']>2){
               freq[s[l]-'a']--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};