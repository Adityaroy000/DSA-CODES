class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        stack<char>st;
        string s;
        while(i<num.size()){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]); 
            i++;           
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
           s.push_back(st.top());
           st.pop();
        }
        reverse(s.begin(),s.end());
        int pos = 0;
        while(pos < s.size() && s[pos]=='0'){
            pos++;
        }
        s = s.substr(pos);
        return s.empty()?"0":s;
    }
};