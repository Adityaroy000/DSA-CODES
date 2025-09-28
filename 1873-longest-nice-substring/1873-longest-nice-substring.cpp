class Solution {
public:
    bool check(string s){
        unordered_set<char>st;
        for(char ch:s){
            st.insert(ch);
        }

        for(int i=0;i<s.size();i++){
            if(s[i] == tolower(s[i])){
                if(st.find(toupper(s[i])) == st.end()){
                    return false;
                }                
            }else{
                if(st.find(tolower(s[i])) == st.end()){
                    return false;
                } 
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";

        for(int i=0;i<n;i++){
            string temp  ="";
            for(int j=i;j<n;j++){
                temp += s[j];
                if(check(temp)){
                    if(temp.size()>ans.size()) ans = temp;
                }
            }
        }
        return ans;
    }
};