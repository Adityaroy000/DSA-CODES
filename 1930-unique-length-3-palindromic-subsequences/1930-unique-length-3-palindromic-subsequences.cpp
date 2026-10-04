class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        int cnt = 0;
        vector<vector<int>>vec(26,vector<int>(2,-1));
        
        // finding first occ and last occ of a char
        for(int i=0;i<n;i++){
            if(vec[s[i]-'a'][0] == -1) vec[s[i]-'a'][0] = i;
            vec[s[i]-'a'][1] = i;
        }

        for(int i=0;i<26;i++){
            // if it appeared only ones then it wont come at _ . _ these two position
            if(vec[i][0] == -1 || vec[i][1] == -1) continue;

            int fo = vec[i][0];
            int lo = vec[i][1];

            // if both index is same that means freq is only for that char so it wont come at _ . _ these two position
            if(fo == lo) continue;

            unordered_set<char>st; // for tracking unique char between fo and lo as they will get counted 

            for(int i=fo+1; i<lo; i++){
                st.insert(s[i]);
            }

            int ss = st.size(); // these many palindrome canbe formed with this char at first and last position.
            cnt += ss;
            st.clear();
        }

        return cnt;
    }
};