class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int maxlen = 0;
        for(int i = 0;i<n;i++){
            int len  = 0;
            unordered_set<char>st;
            for(int j = i; j<n; j++){
                if(st.find(s[j])==st.end()){
                    st.insert(s[j]);
                    len++;
                }else{
                    maxlen = max(len,maxlen);
                    break;
                }
            }
            maxlen = max(len,maxlen);
        }
        return maxlen;
    }
};