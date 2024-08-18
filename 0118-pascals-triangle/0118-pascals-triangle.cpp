class Solution {
public:
vector<int>generaterow(int r){
    vector<int>temp;
    int res =1;
    temp.push_back(1);
    for(int col=1;col<r;col++){
        res = res*(r-col);
        res = res/(col);
        temp.push_back(res);
    }
    return temp;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};