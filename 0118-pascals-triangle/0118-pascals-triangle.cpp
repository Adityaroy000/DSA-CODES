class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int j = 1; j<=numRows; j++){
            if(j==1){
                ans.push_back({1});
            }else if(j==2) ans.push_back({1,1});
            else{
                vector<int>temp;
                temp.push_back(1);
                vector<int>last = ans.back();
                for(int k=0;k<last.size()-1;k++){
                    temp.push_back(last[k]+last[k+1]);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};