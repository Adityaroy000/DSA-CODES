class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int maxlen = 0;
        int l = 0,r = 0;
        unordered_set<char>st;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                maxlen = max(maxlen, r-l+1);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxlen;
    }
};