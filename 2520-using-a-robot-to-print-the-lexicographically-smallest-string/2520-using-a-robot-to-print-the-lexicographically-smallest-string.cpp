class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char>minchararr(n);
        char mini = s[n-1];
        for(int i=n-1;i>=0;i--){
            if(i==n-1) minchararr[i]=s[i];
            else{
                mini = min(mini,s[i]);
                minchararr[i] = mini;
            }
        }

        string p="";
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            while(!st.empty() &&(i== n-1 || st.top()<=minchararr[i+1])){
                p.push_back(st.top());
                st.pop();
            }
            
        }
        return p;
    }
};