class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        vector<string>ans;

        for(int i=0;i<n;i+=k){
            string temp="";
            for(int j=i;j<k+i;j++){
                if(j<n)
                    temp += s[j];
                else
                    temp += fill;
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};