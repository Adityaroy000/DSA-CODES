class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int maxlen = 0,len = 0;
        int l = 0,r = 0;
        unordered_set<char>st;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                len++;
                r++;
            }else{
                st.clear();
                maxlen = max(maxlen,len);
                l++;
                len = 0;
                r = l;
            }
        }
        maxlen = max(maxlen,len);
        return maxlen;
    }
};