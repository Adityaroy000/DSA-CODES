class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>st;
        for(char ch:s) st[ch]++;

        int n = order.size();
        string ans = "";
        for(char ch : order){
            if(st.count(ch)){
                for(int i=1;i<=st[ch];i++) ans.push_back(ch);
                st.erase(ch);
            }
        }

        for(auto it:st){
            for(int i=1;i<=it.second;i++) ans.push_back(it.first);
        }

        return ans;
    }
};