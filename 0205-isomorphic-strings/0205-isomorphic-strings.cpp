class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,char>mpp;
        unordered_set<char>st;

        int n = s.size();

        for(int i=0;i<n;i++){
            if(mpp.count(s[i])){
                s[i] = mpp[s[i]];
                continue;
            }
            if(st.count(t[i])) return false;
            mpp[s[i]] = t[i];
            st.insert(t[i]);
            s[i] = t[i];
        }

        if(s == t) return true;
        return false;
    }
};