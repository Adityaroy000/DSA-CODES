class Solution {
public:
void find(int k,int n,vector<int>& temp,vector<vector<int>>& ans,int i){
    if(temp.size()==k){
        if(n==0) {
            ans.push_back(temp);
        }
        return;
    }
    for(int j = i; j<=9;j++){
        if((n-j)<0) break;
        temp.push_back(j);
        find(k,n-j,temp,ans,j+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0;
        for(int i = 1; i<=k; i++){
            sum+=i;
        }
        if(sum>n) return {};
        vector<int>temp;
        vector<vector<int>>ans;
        find(k,n,temp,ans,1);
        return ans;
    }
};