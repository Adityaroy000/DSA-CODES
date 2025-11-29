class Solution {
public:
    int maxPower(string s) {
        unordered_set<char>st;
        int n = s.size();

        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }

        if(st.size()==n){
            return 1;
        }
        int maxi = 0;
        for(auto &it:st){
            char el = it;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(s[i]==el){
                    cnt++;
                }else cnt = 0;
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};