class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>ans;

        for(int i=0;i<n;i++){
            string sub = words[i];
            for(int j=0;j<n;j++){
                if(i!=j){
                    string s = words[j];
                    if(s.find(sub) != string::npos){
                        ans.push_back(sub);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};