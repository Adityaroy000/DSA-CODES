class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        string p="";
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            st.push(ch);
            if(mpp[ch]==1) mpp.erase(ch);
            else mpp[ch]--;
            bool flag = false;
            for(char c ='a'; c < ch ;c++){
                if(mpp.find(c)!=mpp.end()){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                while(!st.empty()){
                    char chh = st.top();
                    bool valid = false;
                    for(char c='a';c<chh;c++){
                        if(mpp.find(c)!=mpp.end()){
                            valid = true;
                            break;
                        }
                    }
                    if(!valid){
                        p.push_back(st.top());
                        st.pop();
                    }else break;
                }
            }
        }
        return p;
    }
};