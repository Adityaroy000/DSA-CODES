class Solution {
public:
    void solve(int num,int n,vector<int>& ans){
        if(num>n) return;
        ans.push_back(num);

        for(int i=0;i<=9;i++){
            int newnum = (num*10)+i;
            if(newnum>n) return;
            solve(newnum,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        int count = 1;
        
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};