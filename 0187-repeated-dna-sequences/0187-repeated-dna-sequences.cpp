class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        unordered_set<string>ans;
        if(n<10) return {};

        int l=0,r=0;
        unordered_set<string>st;
        string temp = "";
        while(r<n){
            temp += s[r];
            if(r-l+1 == 10){
                if(st.count(temp)){
                    ans.insert(temp);
                }
                else st.insert(temp);
                l++;
                temp.erase(0,1);
            }
            r++;
        }
        vector<string>res(ans.begin(),ans.end());
        
        return res;
    }
};