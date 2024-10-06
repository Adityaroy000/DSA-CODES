class Solution {
public:
    bool ismatching(char c1,char c2){
        if(c1 == '(' && c2 == ')'){
            return true;
        }else if(c1 == '{' && c2 == '}'){
            return true;
        }else if(c1 == '[' && c2 == ']'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int i = 0;
        stack<char>st;
        while(s[i]!='\0'){
            char ch = s[i];
            if(ch == '('||ch=='{'||ch=='['){
                st.push(ch);
            }else if(ch == ')'||ch == '}'||ch == ']'){
                if(st.empty()){
                    return false;
                }
                char ch1 = st.top();
                st.pop();
                if(!ismatching(ch1,ch)){
                    return false;
                }
            }
            i++;
        }
        if(!st.empty()){
            return false;
        }else{
            return true;
        }
    }
};