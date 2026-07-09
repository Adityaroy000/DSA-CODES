class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();

        int sl=0, tl=0;

        while(sl<n && tl<m){
            if(s[sl] == t[tl]){
                tl++;
            }

            sl++;
        }

        if(tl<m){
            return m-tl;
        }

        return 0;
    }
};