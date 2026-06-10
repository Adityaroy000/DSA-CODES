class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            int ch = i-1;

            if(ch<0) {
                ans.push_back(temp);
                continue;
            }
            if(ch==0) {
                temp.push_back(1);
                ans.push_back(temp);
                continue;
            }

            vector<int>prev = ans[i-1];

            for(int j=0; j<i-1;j++){
                int sum = prev[j]+prev[j+1];
                temp.push_back(sum);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }
        return ans;
    }
};