class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        vector<int>ans;
        for(int j=0;j<n;j++){
            for(int i=0;i<words[j].size();i++){
                if(words[j][i]==x) {
                    ans.push_back(j);
                    break;
                }
            }
        }

        return ans;
    }

};