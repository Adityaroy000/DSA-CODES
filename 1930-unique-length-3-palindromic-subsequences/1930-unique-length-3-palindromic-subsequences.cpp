class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        int cnt = 0;
        vector<vector<int>>vec(26,vector<int>(2,-1));

        for(int i=0;i<n;i++){
            if(vec[s[i]-'a'][0] == -1) vec[s[i]-'a'][0] = i;
            vec[s[i]-'a'][1] = i;
        }

        for(int i=0;i<26;i++){
            if(vec[i][0] == -1 || vec[i][1] == -1) continue;

            int fo = vec[i][0];
            int lo = vec[i][1];

            if(fo == lo) continue;

            unordered_set<char>st;

            for(int i=fo+1; i<lo; i++){
                st.insert(s[i]);
            }

            int ss = st.size();
            cnt += ss;
            st.clear();
        }

        return cnt;
    }
};